//
// Created by SICH on 24.03.2022.
//

#ifndef STACK_C_RPN_H
#define STACK_C_RPN_H
enum token_type {NUMBER, OP, LB, RB, FUNC, COMMA};

typedef struct token{
    char* name;
    enum token_type type;
    struct token* next;
}token;

typedef struct operator_node{
    char* op[1];
    int precedence;
    struct operator_node * next;
}operator_node;

typedef struct operator_stack{
    operator_node* head;
}operator_stack;

int solve_expression_immediately(char *s);
token* shunting_yard(token* infix_notion);
int solve_expression(token* polish);
void print_token(token *node);
token* infix_str_to_token_node(char* str);
#endif //STACK_C_RPN_H
