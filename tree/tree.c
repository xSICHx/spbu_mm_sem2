#include <stdio.h>
#include <stdlib.h>
#define LENARR(a) sizeof(a)/sizeof(int)

struct tree {
    int val;
    struct tree *left;
    struct tree *right;
};

struct tree *get_node (int val) {
    struct tree *node = (struct tree*) malloc(sizeof(struct tree));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct tree* tree_create(const int *a, size_t len){
    struct tree *result, *p_next, *p;
    result = get_node(a[0]);
    for (int i = 1; i < len; i++){
        p = result;
        p_next = (a[i] < p->val) ? p->left : p->right;
        while (p_next){
            p = p_next;
            p_next = (a[i] < p_next->val) ? p_next->left : p_next->right;
        }
        p_next = get_node(a[i]);
        if (a[i] < p->val) p->left = p_next;
        else p->right = p_next;
    }
    return result;
}

void array_sort(struct tree *bin_tree, int *a, int *j){
    struct tree *p = bin_tree;
    if (p->left) array_sort(p->left, a, j);
    a[*j] = p->val;
    (*j)++;
    if (p->right) array_sort(p->right, a, j);
}

void tree_sort(int *a, int len){
    struct tree *lst;
    lst = tree_create(a, len);
    int j = 0;
    array_sort(lst, a, &j);
}

void printarr(int *a, int len){
    for (int i = 0; i < len; i++){
        printf("%d ", a[i]);
    }
}

int main() {
    int a[] = {5, -10, 15, 3, 16, 73,-23, -6};
    tree_sort(a, LENARR(a));
    printarr(a, LENARR(a));
    printf("\n");
    int b[] = {36, 20, -33, 0, 1245, 2, -30, 20, -234};
    tree_sort(b, LENARR(b));
    printarr(b, LENARR(b));
    return 0;
}
