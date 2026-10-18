// Computes the maximum rental revenue as the longest Start -> End path.
//
// This graph puts a client's revenue on its INCOMING edges
// (Start -> i and j -> i weigh rev_i; edges into End weigh 0),
// so the recurrence uses each edge's own weight:
//
//   F(End) = 0
//   F(v)   = max over edges v -> u of ( w(v -> u) + F(u) )
//   opt[v] = the u that produced that max
//
// Vertices are processed in REVERSE topological order, so every F(u)
// a vertex needs has already been computed when that vertex is reached.

#include "RevenueOptimizer.h"

#include <climits>

using namespace std;

RevenueResult RevenueOptimizer::optimize(const DAG& dag,
                                         const vector<int>& topoOrder) {
    const int numVertices = dag.vertexCount();
    const int numClients  = numVertices - 2;
    const int start = DAG::startVertex(numClients);
    const int end   = DAG::endVertex(numClients);

    // F[v] = best revenue from v to End. LLONG_MIN marks "not computed yet".
    vector<long long> F(numVertices, LLONG_MIN);
    // opt[v] = next vertex on the best path out of v (-1 for End).
    vector<int> opt(numVertices, -1);

    F[end] = 0;

    for (auto it = topoOrder.rbegin(); it != topoOrder.rend(); ++it) {
        const int v = *it;
        if (v == end) {
            continue;
        }

        for (const Edge& edge : dag.neighbors(v)) {
            if (F[edge.to] == LLONG_MIN) {
                continue;  // neighbor has no path to End
            }
            const long long candidate = edge.weight + F[edge.to];
            // Strict '>' keeps the first neighbor that reaches the max on ties.
            if (candidate > F[v]) {
                F[v]   = candidate;
                opt[v] = edge.to;
            }
        }
    }

    // Follow opt from Start to End, keeping only client vertices (1..n).
    RevenueResult result;
    result.maxRevenue = F[start];
    for (int v = opt[start]; v != -1 && v != end; v = opt[v]) {
        result.clientIds.push_back(v);  // client k is vertex k
    }
    return result;
}
