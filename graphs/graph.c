#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

graph* graph_init(int n){
    graph* result = (graph*)malloc(sizeof(graph));
    result->count = n;
    if (n) result->adj_list = (node**)malloc(n*(sizeof(node*)));
    else result->adj_list = NULL;
    for (int i = 0; i < n; i++) result->adj_list[i] = NULL;
    return result;
}

node* node_init(int val){
    node* result = (node*)malloc(sizeof(node));
    result->val = val;
    result->next = NULL;
    return result;
}

void add_arc(graph* g, int beg, int end){
    // проверка на вхождение в граф
    node* temp = g->adj_list[beg];
    while (temp){
        if (temp->val == end) return;
        temp = temp->next;
    }
    node* new_node = node_init(end);
    new_node->next = g->adj_list[beg];
    g->adj_list[beg] = new_node;
}

void add_edge(graph* g, int a, int b){
    add_arc(g, a, b);
    add_arc(g, b, a);
}

void del_arc(graph* g, int beg, int end){
    //проверка на существование ребра
    if (beg >= g->count){ perror("Too big index of vertex to del"); return;}
    node* temp = g->adj_list[beg];
    while (temp){
        if (temp->val == end) break;
        temp = temp->next;
    }
    if (!temp){ perror("There are no such vertices"); return;}

    temp = g->adj_list[beg];
    if (g->adj_list[beg]->val == end){
        g->adj_list[beg] = g->adj_list[beg]->next;
        free(temp);
        temp = NULL;
    }
    else{
        while (temp-> next && temp->next->val != end) temp = temp->next;
        node* to_become_free = temp->next;
        temp->next = temp->next->next;
        free(to_become_free);
    }
}

void del_edge(graph* g, int beg, int end){
    del_arc(g, beg, end);
    del_arc(g, end, beg);
}

void graph_print(graph* g){
    int i;
    for (i = 0; i < g->count; i++){
        node* temp = g->adj_list[i];
        printf("%d: ", i);
        while (temp){
            printf("%d ", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}

void graph_free(graph* g){
    int i;
    node* temp;
    for (i = 0; i < g->count; i++){
        while (g->adj_list[i]){
            temp = g->adj_list[i];
            g->adj_list[i] = g->adj_list[i]->next;
            free(temp);
        }
    }
    free(g->adj_list);
    free(g);
}


stack* stack_init(){
    stack* s = (stack*)malloc(sizeof(stack));
    s->head = NULL;
    return s;
}

void stack_push(stack* s, int vertex){
    node* n = (node*)malloc(sizeof(node));
    n->next = s->head;
    n->val = vertex;
    s->head = n;
}

void stack_pop(stack* s){
    node* n = s->head;
    s->head = s->head->next;
    free(n);
}

void array_fill(int* a, size_t size, int x){
    for (int i = 0; i < size; i++) *(a+i) = x;
}

int dfs_check_bipartite(graph* g, int* color){
    int clr, i, flag = 1; node* temp; // flag для несвязных графов
    array_fill(color, g->count, 2);
    //for (i = 0; i < g->count; i++) printf("%d ", color[i]);
    stack* s = stack_init();
    stack_push(s, 0);
    color[0] = 0;
    while (flag) {
        while (s->head) {
            //printf("%d: \n", s->head->val);
            clr = color[s->head->val];
            temp = g->adj_list[s->head->val];
            stack_pop(s);
            while (temp) {
                if (clr == color[temp->val]) return 0;
                if (color[temp->val] == 2) {
                    color[temp->val] = !(clr);
                    stack_push(s, temp->val);
                }
                //printf("   %d color = %d", temp->val, color[temp->val]);
                temp = temp->next;
            }
            //printf("\n");
        }
        flag = 0;
        for (i = 0; i < g->count; i++) {
            if (color[i] == 2){
                flag = 1;
                color[i] = 0;
                stack_push(s, i);
                break;
            }
        }
    }
    return 1;
}


queue* queue_init(){
    queue* q = (queue*)malloc(sizeof(queue));
    q->head = q->tail = NULL;
    return q;
}

void queue_push(queue* q, int vertex){
    node* n = (node*)malloc(sizeof(node));
    n->next = NULL;
    n->val = vertex;
    if (q->head){
        q->tail->next = n;
        q->tail = q->tail->next;
    }
    else q->head = q->tail = n;
}

void queue_pop(queue* q){
    node* n = q->head;
    if (q->head == q->tail) q->head = q->tail = NULL;
    else q->head = q->head->next;
    free(n);
}

int bfs_check_bipartite(graph* g){
    int color[g->count], clr, i, flag = 1; node* temp; // flag для несвязных графов
    array_fill(color, sizeof(color)/sizeof(int), 2);
    //for (i = 0; i < g->count; i++) printf("%d ", color[i]);
    queue * q = queue_init();
    queue_push(q, 0);
    color[0] = 0;
    while (flag) {
        while (q->head) {
            //printf("%d: \n", s->head->val);
            clr = color[q->head->val];
            temp = g->adj_list[q->head->val];
            queue_pop(q);
            while (temp) {
                if (clr == color[temp->val]) return 0;
                if (color[temp->val] == 2) {
                    color[temp->val] = !(clr);
                    queue_push(q, temp->val);
                }
                //printf("   %d color = %d", temp->val, color[temp->val]);
                temp = temp->next;
            }
            //printf("\n");
        }
        flag = 0;
        for (i = 0; i < g->count; i++) {
            if (color[i] == 2){
                flag = 1;
                color[i] = 0;
                queue_push(q, i);
                break;
            }
        }
    }
    printf("First: ");
    for (i = 0; i < g->count; i++){
        if (color[i] == 0) printf("%d ", i);
    }
    printf("\nSecond: ");
    for (i = 0; i < g->count; i++){
        if (color[i] == 1) printf("%d ", i);
    }
    return 1;
}

int graph_write(graph* g, char* filename){
    FILE* f = fopen(filename, "w");
    int i;
    for (i = 0; i < g->count; i++){
        node* temp = g->adj_list[i];
        fprintf(f, "%d:", i);
        while (temp){
            fprintf(f, " %d", temp->val);
            temp = temp->next;
        }
        fprintf(f, "\n");
    }
    fclose(f);
    return 0;
}

void graph_realloc(graph* g, int n){
//    node** p_adj = (node**)realloc(g->adj_list, (n)*sizeof(node*));
//    if (p_adj = NULL){
//        printf("ERR");
//        return;
//    }
    g->adj_list = (node**)realloc(g->adj_list, (n)*sizeof(node*));
    for (int i = g->count; i < n; i++) g->adj_list[i] = NULL;
    g->count = n;
}

graph* graph_read(char* filename){
    int vertex_main, vertex_n, i = 0; char buff[11], c;
    FILE* f = fopen(filename, "r");
    if (f == NULL) perror("Wrong name of file");
    graph* g = graph_init(0);
    while ((c = fgetc(f)) != EOF){
        buff[i] = c;
        i++;
        if (c == ' ' || c == '\n'){
            vertex_n = strtol(buff, NULL, 10);
            //printf("%d %d;", vertex_main, vertex_n);
            add_arc(g, vertex_main, vertex_n);
            i = 0;
        }
        if (c == ':'){
            i = 0;
            vertex_main = strtol(buff, NULL, 10);
            if (vertex_main + 1 > g->count) graph_realloc(g, vertex_main + 1);
            c = fgetc(f);
            if (!(c == ' ' || c == '\n')) perror("Wrong input, try to add space after :");
        }
    }
    fclose(f);
    return g;
}

graph* topology_sort(graph* g, int vert){
    int color[g->count], sorted_vertexes[g->count], j = g->count-1; node* temp;
    int flag_if_all_black = 1, flag = 1;
    array_fill(color, g->count, 0);
    graph* result = graph_init(g->count);
    stack* s = stack_init();
    stack_push(s, vert);
    while (flag) {
        while (s->head) {
            if (g->adj_list[s->head->val]) {
                //if (color[s->head->val] == 2) stack_pop(s);
                if (color[s->head->val] == 0) color[s->head->val] = 1;
                else {
                    temp = g->adj_list[s->head->val];
                    while (temp) {
                        if (color[temp->val] == 1) return NULL;
                        if (color[temp->val] == 0) {
                            stack_push(s, temp->val);
                            flag_if_all_black = 0;
                        }
                        temp = temp->next;
                    }
                    if (flag_if_all_black == 1) {
                        color[s->head->val] = 2;
                        sorted_vertexes[j] = s->head->val;
                        j--;
                        stack_pop(s);
                    }
                    flag_if_all_black = 1;
                }
            }
            else {
                color[s->head->val] = 2;
                //printf("%d\n", s->head->val);
                sorted_vertexes[j] = s->head->val;
                j--;
                stack_pop(s);
            }
        }
        flag = 0;
        for (int i = 0; i < g->count; i++){
            if (color[i] == 0){
                stack_push(s, i);
                flag = 1;
                break;
            }
        }
    }
    for (int i = 0; i < g->count; i++){
        temp = g->adj_list[sorted_vertexes[i]];
        while (temp){
//            temp->val = sorted_vertexes[temp->val];
            add_arc(result, i, sorted_vertexes[temp->val]);
            temp = temp->next;
        }
    }
    return result;
}