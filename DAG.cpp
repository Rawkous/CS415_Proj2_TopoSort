// Implementation of the Directed Acyclic Graph

#include "DAG.h"

using namespace std;

DAG::DAG(int numVertices)
    : numVertices(numVertices),
      adjList(numVertices),
      inDegrees(numVertices, 0) {
}

void DAG::addEdge(int from, int to, long long weight) {
    
}

int DAG::vertexCount() const {
    return numVertices;
}

const vector<Edge>& DAG::neighbors(int vertex) const {
    // TODO: Return the outgoing edges for vertex.
    static const vector<Edge> emptyNeighbors;
    return emptyNeighbors;
}

int DAG::inDegree(int vertex) const {
    // TODO: Return the in-degree for vertex.
    return 0;
}

DAG constructDAG(const vector<Client>& clients) {
    // TODO: Construct the graph from the client rental requests.
    return DAG(static_cast<int>(clients.size()) + 2);
}
