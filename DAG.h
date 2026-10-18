#ifndef DAG_H
#define DAG_H

#include "Client.h"
#include <vector>

struct Edge {
    int to;
    long long weight;
};

// Vertices are numbered 0 = Start, 1..n = clients, and n + 1 = End.
class DAG {
public:
    explicit DAG(int numVertices);

    void addEdge(int from, int to, long long weight);
    int vertexCount() const;
    const std::vector<Edge>& neighbors(int vertex) const;
    int inDegree(int vertex) const;

    static int startVertex(int numClients);
    static int endVertex(int numClients);
    static DAG constructDAG(const std::vector<Client>& clients);

private:
    int numVertices;
    std::vector<std::vector<Edge>> adjList;
    std::vector<int> inDegrees;
};

#endif // DAG_H
