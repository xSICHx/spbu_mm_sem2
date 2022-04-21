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
//    add_arc(g, 4, 2);
    graph_print(g);
    graph* g1 = topology_sort(g, 0);
    if (g1) graph_print(g1);
    else printf("cyclic graph");
    return 0;
}

void graph_test_files(){
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
    graph_write(g, "../graph.txt");
    graph* g1 = graph_read("../graph.txt");
    printf("Graph created with file: \n");
    graph_print(g1);
    graph_free(g);
    graph_free(g1);
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
    test_top_sort();
    return 0;
}
