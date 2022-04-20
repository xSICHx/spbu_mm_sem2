#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//идея в том, что будем хранить левого и правого предка
typedef struct sb{
    int up_left;
    int down_left;
    int up_right;
    int down_right;
    struct sb *left;
    struct sb *right;
}sb;

sb *get_sb_node(int ul, int dl, int ur, int dr) {
    sb *node = (sb*) malloc(sizeof(sb));
    node->up_left = ul;
    node->down_left = dl;
    node->up_right = ur;
    node->down_right = dr;
    return node;
}

void get_st_br_subtree(int depth, sb* node){
    if (depth == 0){
        node->left = NULL;
        node->right = NULL;
        return;
    }
    node->left = get_sb_node(node->up_left, node->down_left,
            node->up_left + node->up_right,
            node->down_left + node->down_right);
    get_st_br_subtree(depth-1, node->left);

    node->right = (sb*) malloc(sizeof(sb));
    node->right->up_left = node->up_left + node->up_right;
    node->right->down_left = node->down_left + node->down_right;
    node->right->up_right = node->up_right;
    node->right->down_right = node->down_right;
    get_st_br_subtree(depth-1, node->right);
}

sb *get_st_br_tree(int n){
    sb *result = get_sb_node(0,1,1,0);
    get_st_br_subtree(n-1, result);
    return result;
}
void sb_number(double r, sb* tree){
    sb* node = tree;
    double x = (double)(node->up_left + node->up_right) / (double)(node->down_left +
            node->down_right);
    while (node->left){
        if (r < x){ node = node->left;
            printf("L");}
        else {node = node->right;
            printf("R");}
        x = (double)(node->up_left + node->up_right) / (double)(node->down_left +
                node->down_right);
    }
    printf("\n%f", x);
}

int main() {
    sb* node = get_st_br_tree(20);
    sb_number(1.618033, node);
    return 0;
}
