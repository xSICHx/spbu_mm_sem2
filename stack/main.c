#include <stdio.h>
#include <stdlib.h>
#include "solve_rpn.h"
char* input(){
    char* s = malloc(100000);
    gets(s);
    return s;
}


int main() {
    token* notation = infix_str_to_token_node("-1+2*(3+1)/2*GCD(-2, 4)");
    print_token(notation);
    printf("\n");
    token* polish = shunting_yard(notation);
    print_token(polish);
    printf("\n");
    int res = solve_expression(polish);
    printf("%d", res);

//    int result;
//    for (int i = 0; i < 10; i++){
//        result = solve_expression_immediately(input());
//        printf("%d\n", result);
//    }

//    result = solve_expression_immediately("2+GCD(34-1,11)*2-1");
//    printf("%d\n", result);
    //"1+(-45*2+GCD(33,64/4))*3-2"
    return 0;
}