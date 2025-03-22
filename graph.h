#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

class Graph {
private:
    std::vector<std::vector<int>> adjList;
public:
    Graph(int nodes);
    void create(int u, int v);
    void read();
    void deleteNode(int u, int v);
};
#endif
