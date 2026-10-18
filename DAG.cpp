#include "DAG.h"

DAG::DAG(int numVertices)
    : numVertices(numVertices),
      adjList(numVertices),
      inDegrees(numVertices, 0) {
}

void DAG::addEdge(int from, int to, long long weight) {
    adjList.at(from).push_back({to, weight});
    ++inDegrees.at(to);
}

int DAG::vertexCount() const {
    return numVertices;
}

const std::vector<Edge>& DAG::neighbors(int vertex) const {
    return adjList.at(vertex);
}

int DAG::inDegree(int vertex) const {
    return inDegrees.at(vertex);
}

int DAG::startVertex(int numClients) {
    (void)numClients;
    return 0;
}

int DAG::endVertex(int numClients) {
    return numClients + 1;
}

DAG DAG::constructDAG(const std::vector<Client>& clients) {
    const int numClients = static_cast<int>(clients.size());
    DAG dag(numClients + 2);

    // Incoming edges carry the destination client's revenue, matching the
    // recurrence used by RevenueOptimizer.
    for (const Client& from : clients) {
        for (const Client& to : clients) {
            if (from.id != to.id && from.end <= to.start) {
                dag.addEdge(from.id, to.id, to.revenue);
            }
        }
    }

    const int start = startVertex(numClients);
    const int end = endVertex(numClients);
    for (const Client& client : clients) {
        if (dag.inDegree(client.id) == 0) {
            dag.addEdge(start, client.id, client.revenue);
        }
        if (dag.neighbors(client.id).empty()) {
            dag.addEdge(client.id, end, 0);
        }
    }

    return dag;
}
