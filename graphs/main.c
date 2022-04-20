#include "stdio.h"
#include "graph.h"

int test_top_sort() {
    graph* g = graph_init(4);
    add_arc(g, 0, 3);
    add_arc(g, 3, 1);
    add_arc(g, 3, 2);
    add_arc(g, 2, 1);
    add_arc(g, 1, 3);
    del_arc(g, 1, 3);
    graph* g1 = topology_sort(g, 0);
    if (g1) graph_print(g1);
    else printf("cyclic graph");
    return 0;
}

void graph_test_1() {
    graph* g = graph_init(7);
    for (int i = 0; i < 6; i++)
        add_edge(g, 0, i);
//    add_edge(g, 0, 2);
//    add_edge(g, 1, 2);
//    add_edge(g, 1, 4);
//    add_edge(g, 1, 3);
//    add_edge(g, 2, 4);
//    add_edge(g, 3, 4);
//    add_edge(g, 4, 6);
//    add_edge(g, 5, 1);
//    add_edge(g, 5, 6);
    del_edge(g, 3, 4);
    del_edge(g, 0, 3);
    graph_print(g);
    graph_free(g);
}

int main() {
    graph_test_1();
    return 0;
}
