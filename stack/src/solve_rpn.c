#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../solve_rpn.h"
#include "../euclid.h"

#define token_fill(last_token, size, s, tpe) last_token->next = (token*)malloc(sizeof(token)); \
last_token = last_token->next; \
last_token->name = malloc(size); \
if (tpe == NUMBER) strcpy(last_token->name, s); \
else last_token->name[0] = s[0]; \
last_token->type = tpe

int determine_precedence(const char s){
    if (s == '(' || s == 'G' || s == 'L') return 0;
    if (s == '+' || s == '-') return 1;
    return 2;
}

void stack_push(operator_stack* op_stack, char* op){
    operator_node* n = (operator_node*)malloc(sizeof(operator_node));
    n->next = op_stack->head;
    n->precedence = determine_precedence(op[0]);
    n->op[0] = &op[0];
    op_stack->head = n;
}

void stack_pop(operator_stack* op_stack){
    operator_node* n = op_stack->head;
    op_stack->head = op_stack->head->next;
    //free(n->op);
    free(n);
}

void add_zero_to_notion(token* last_token){
    last_token->name = malloc(2);
    last_token->name[0] = '0';
    last_token->name[1] = '\0';
    last_token->type = NUMBER;
}

token* infix_str_to_token_node(char* str){
    char* s = str, * p;
    token* result = (token*)malloc(sizeof(token));
    add_zero_to_notion(result);
    token *last_token = result;

    last_token->next = (token*)malloc(sizeof(token));
    last_token->next->type = OP;
    last_token->next->name = malloc(1);
    if (*s == ' ') s++;
    if (*s == '-'){
        last_token->next->name[0] = '-';
        s++;
    }
    else last_token->next->name[0] = '+';
    last_token = last_token->next;

    while (*s != '\0'){
        if (*s == ' ') s++;
        last_token->next = (token*)malloc(sizeof(token));
        last_token->next->name = malloc(1);
        last_token->next->name[0] = *s;
        if (*s == '-' || *s == '+' || *s == '*' || *s == '/') last_token->next->type = OP;
        if (*s == '('){
            last_token->next->type = LB;
            if (*(s+1) == '-'){
                last_token = last_token->next;
                last_token->next = (token*)malloc(sizeof(token));
                add_zero_to_notion(last_token->next);
            }
        }
        if (*s == ')') last_token->next->type = RB;
        if (*s == ','){
            last_token->next->type = COMMA;
            if (*(s+1) == '-'){
                last_token = last_token->next;
                last_token->next = (token*)malloc(sizeof(token));
                add_zero_to_notion(last_token->next);
            }
        }
        if (*s == 'G' || *s == 'L'){
            last_token->next->type = FUNC;
            if (*(s+4) == '-'){
                last_token = last_token->next;
                last_token->next = (token*)malloc(sizeof(token));
                add_zero_to_notion(last_token->next);
            }
            s += 3;
        }
        if ('0' <= *s && *s <= '9'){
            last_token->next->type = NUMBER;
            last_token->next->name = (char*)realloc(last_token->next->name, 20);
            itoa(strtol(s, &p, 10), last_token->next->name, 10);
            s = p-1;
        }
        s++;
        last_token = last_token->next;
    }
    last_token->next = NULL;
    return result;
}

void print_token(token *node){
    token *temp = node;
    char* s;
    while (temp){
        if (temp->type == NUMBER){
            s = temp->name;
            while (*s != '\0'){
                printf("%c", *s);
                s++;
            }
        }
        else printf("%c", *temp->name);
        printf(" ");
        temp = temp->next;
    }
}


token* shunting_yard(token* infix_notion){
    token* infix = infix_notion->next->next;

    operator_stack* op_stack = (operator_stack*)malloc(sizeof(operator_stack));
    op_stack->head = NULL;
    stack_push(op_stack, &infix_notion->next->name[0]);

    token* result = (token*)malloc(sizeof(token));
    add_zero_to_notion(result);
    token* last_token = result;
    while (infix){
        if (infix->type == NUMBER){
            token_fill(last_token, 20, infix->name, NUMBER);
        }
        if (infix->type == OP){
            if (determine_precedence(infix->name[0]) <= op_stack->head->precedence){
                while (op_stack->head){
                    if (determine_precedence(infix->name[0]) >
                    op_stack->head->precedence){
                        break;
                    }
                    else{
                        token_fill(last_token, 1, op_stack->head->op[0], OP);
                        stack_pop(op_stack);
                    }
                }
            }
            stack_push(op_stack, infix->name);
        }
        if (infix->type == LB || infix->type == FUNC) stack_push(op_stack, infix->name);
        if (infix->type == RB){
            while (op_stack->head->precedence){
                token_fill(last_token, 1, op_stack->head->op[0], OP);
                stack_pop(op_stack);
            }
            if (*op_stack->head->op[0] == 'G' || *op_stack->head->op[0] == 'L'){
                token_fill(last_token, 1, op_stack->head->op[0], OP);
            }
            stack_pop(op_stack);
        }
        if (infix->type == COMMA){
            while (op_stack->head->precedence){
                token_fill(last_token, 1, op_stack->head->op[0], OP);
                stack_pop(op_stack);
            }
        }
        infix = infix->next;
    }
    while (op_stack->head){
        token_fill(last_token, 1, op_stack->head->op[0], OP);
        stack_pop(op_stack);
    }
    last_token->next = NULL;
    return result;
}

int solve_expression(token* polish){
    int result;
    token* last_token = polish;
    int len = 1;
    int* a = malloc(len*sizeof(int));
    a[0] = strtol(last_token->name, NULL, 10);
    last_token = last_token->next;
    while (last_token){
        if (last_token->type == NUMBER){
            len++;
            a = (int*)realloc(a, len*sizeof(int));
            a[len-1] = strtol(last_token->name, NULL, 10);
        }
        else{
            if (len - 1 < 0 || len-2 < 0) return -2147483648;
            if (last_token->name[0] == '+') a[len-2] += a[len-1];
            else if (last_token->name[0] == '-') a[len-2] -= a[len-1];
            else if (last_token->name[0] == '*') a[len-2] *= a[len-1];
            else if (last_token->name[0] == '/') a[len-2] /= a[len-1];
            else if (last_token->name[0] == 'G') a[len-2] = euclid(a[len-2], a[len-1]);
            else if (last_token->name[0] == 'L') a[len-2] = a[len-2] *a[len-1] / euclid
                    (a[len-2],
                    a[len-1]);
            else return -2147483648;
            len--;
            a = (int*)realloc(a, len*sizeof(int));
        }
        //printf("%c \n", last_token->name[0]);
        last_token = last_token->next;
    }
    result = a[0];
    free(a);
    return result;
}

int solve_expression_immediately(char *s){
    if (*s == '\0') return 0;
    token* notation = infix_str_to_token_node(s);
    token* temp;
    token* polish = shunting_yard(notation);
    int result = solve_expression(polish);
    while (notation){
        temp = notation;
        notation = notation->next;
        free(temp->name);
        free(temp);
    }
    while (polish){
        temp = polish;
        polish = polish->next;
        free(temp->name);
        free(temp);
    }
    return result;
}

