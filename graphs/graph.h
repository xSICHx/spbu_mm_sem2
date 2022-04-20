//
// Created by SICH on 29.03.2022.
//

#ifndef GRAPH_C_GRAPH_H
#define GRAPH_C_GRAPH_H

typedef struct node{
    int val;
    struct node* next;
}node;

typedef struct stack{
    node* head;
}stack;

typedef struct graph{
    int count;
    node** adj_list;
}graph;

graph* graph_init(int n);
void add_arc(graph* g, int beg, int end);
void add_edge(graph* g, int a, int b);
void del_arc(graph* g, int beg, int end);
void del_edge(graph* g, int beg, int end);
void graph_print(graph* g);
void graph_free(graph* g);

typedef struct queue{
    struct node* head;
    struct node* tail;
}queue;

int dfs_check_bipartite(graph* g, int* color);
int bfs_check_bipartite(graph* g);

graph* topology_sort(graph* g, int vert);

int graph_write(graph* g, char* filename);
graph* graph_read(char* filename);
#endif //GRAPH_C_GRAPH_H
