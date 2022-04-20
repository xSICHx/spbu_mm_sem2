#include <stdio.h>
#include <stdlib.h>
#include "../graph.h"


int main() {
    graph* g = graph_init(11);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
//    add_edge(g, 0, 3);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 1, 4);
    add_edge(g, 4, 5);
    add_edge(g, 3, 5);
    add_edge(g, 4, 3);
    del_edge(g, 4, 3);
    add_edge(g, 4, 9);
    add_edge(g, 6, 7);
    add_edge(g, 7, 8);
//    del_edge(g, 2, 3);
//    add_edge(g, 6, 8);
//    graph_print(g);
    int* color = malloc(sizeof(int)*g->count);
    if (dfs_check_bipartite(g, color)) printf("Your graph is bipartite! Checked by "
                                            "dfs\n");
    else printf("You always can delete some edges) Checked by dfs\n");
    printf("First: ");
    for (int i = 0; i < g->count; i++){
        if (color[i] == 0) printf("%d ", i);
    }
    printf("\nSecond: ");
    for (int i = 0; i < g->count; i++){
        if (color[i] == 1) printf("%d ", i);
    }

    add_edge(g, 6, 8);
    if (bfs_check_bipartite(g)) printf("\nYour graph is bipartite! Checked by "
                                              "bfs");
    else printf("\nYou always can delete some edges) Checked by bfs");
    graph_free(g);
    return 0;
}
