// TODO: DONE; Decide which algorithm to use when implementing the TopoSort. Queue Based = extra credit
// Topological Sort implementation for DAG using a queue-based approach (Kahn's algorithm).
#ifndef TOPOSORT_H
#define TOPOSORT_H

#include "DAG.h"

#include <vector>
#include <queue>

using namespace std;

class TopoSortQueue {
public:
    // Performs topological sorting on the given Directed Acyclic Graph (DAG).
    // Returns a vector containing the vertices in topologically sorted order.
    static std::vector<int> topoSort(const DAG& dag);

};  

#endif // TOPOSORT_H
