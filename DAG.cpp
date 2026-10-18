// Implementation of the Directed Acyclic Graph

#include "DAG.h"

using namespace std;

DAG::DAG(int numVertices)
    : numVertices(numVertices),
      adjList(numVertices),
      inDegrees(numVertices, 0) {
}

void DAG::addEdge(int from, int to, long long weight) {
    adjList[from].push_back({to, weight});
    inDegrees[to]++;
}

int DAG::vertexCount() const {
    return numVertices;
}

const vector<Edge>& DAG::neighbors(int vertex) const {
    return adjList[vertex];
}

int DAG::inDegree(int vertex) const {
    return inDegrees[vertex];
}

int DAG::startVertex(int numClients) {
    (void)numClients;
    return 0;
}

int DAG::endVertex(int numClients) {
    return numClients + 1;
}

DAG DAG::constructDAG(const vector<Client>& clients) {
    /* Client Struct
    typedef struct {
    int id;
    int start;
    int end;
    long long revenue;
    } Client;*/

    int numClients = clients.size();
    DAG dag(numClients + 2); // +2 for start and end vertices
    
    // Add edges from the start vertex to all clients
    for (const auto& client : clients) {
        dag.addEdge(startVertex(numClients), client.id, client.revenue);
    }

    // Add edges between clients based on their rental periods
    for (size_t i = 0; i < clients.size(); ++i) {
        for (size_t j = 0; j < clients.size(); ++j) {
            if (i != j && clients[i].end <= clients[j].start) {
                dag.addEdge(clients[i].id, clients[j].id, clients[j].revenue);
            }
        }
    }
    
    // Add edges from all clients to the end vertex
    for (const auto& client : clients) {
        dag.addEdge(client.id, endVertex(numClients), 0);
    }

    return dag;
}
