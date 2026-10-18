#ifndef DAG_H
#define DAG_H

#include "Client.h"
#include <vector>

using namespace std;

// Vertex numbering used by the rental graph:
//   0       = Start
//   1..n    = clients 1..n
//   n + 1   = End
//
// An edge means that the destination client can follow the source client
// without overlapping rental dates.
struct Edge {
    int to;
    long long weight;
};

// Adjacency-list representation of the rental DAG.
class DAG {
public:
    explicit DAG(int numVertices);

    // Add an edge and update the destination's in-degree.
    void addEdge(int from, int to, long long weight);

    // Read-only graph information used by other algorithms.
    int vertexCount() const;

    const vector<Edge>& neighbors(int vertex) const;

    int inDegree(int vertex) const;

    // Special vertex indices for a graph containing numClients clients.
    static int startVertex(int numClients);
    static int endVertex(int numClients);

    // Build a rental DAG from the supplied clients.
    static DAG constructDAG(const vector<Client>& clients);

private:
    int numVertices;
    vector<vector<Edge>> adjList;
    vector<int> inDegrees;
};


#endif // DAG_H
