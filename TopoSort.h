#ifndef TOPOSORT_H
#define TOPOSORT_H

#include "DAG.h"
#include <vector>

// Topological sorting returns a list of graph vertex indices in an order where
// every vertex appears before all of its outgoing neighbors.
//
// The graph uses these indices:
//   0       = Start
//   1..n    = clients 1..n
//   n + 1   = End
//
// Recommended approach: queue-based decrease-by-one (Kahn's algorithm).
// This earns the project's queue-based extra credit and runs in O(V + E).
//
// Implementation plan for TopoSort.cpp:
// 1. Create a vector<int> remainingInDegrees with one entry per vertex.
// 2. Copy graph.inDegree(vertex) into that vector. Do not modify the graph's
//    own in-degree values because later algorithms may reuse the graph.
// 3. Put every vertex whose copied in-degree is zero into a queue.
// 4. While the queue is not empty, remove its front vertex and append it to
//    the sorted result.
// 5. For each Edge in graph.neighbors(current), decrement the destination's
//    copied in-degree. If it reaches zero, put that destination in the queue.
// 6. If the result does not contain graph.vertexCount() vertices, the graph
//    contains a cycle and is not a valid DAG.
std::vector<int> topologicalSort(const DAG& graph);

#endif // TOPOSORT_H
