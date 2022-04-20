#include <stdio.h>
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
    //graph_print(g);
    graph_write(g, "../graph.txt");
    graph* g1 = graph_read("../graph.txt");
    graph_print(g1);
    graph_free(g);
    return 0;
}
