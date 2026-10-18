#include "TopoSort.h"
#include "DAG.h"
#include <stdexcept>

using namespace std;


/*
Performs topological sorting on the given Directed Acyclic Graph (DAG).
Returns a vector containing the vertices in topologically sorted order.*/ 
vector<int> TopoSortQueue::topoSort(const DAG &dag) {
  
  // Vector to store the in-degree of each vertex
  vector<int> inDegree(dag.vertexCount(), 0);
  // Queue to store vertices with in-degree 0
  queue<int> zeroInQueue;
  // Vector to store the topological order
  vector<int> topoResult;

  // Calculate the in-degree of each vertex
  for (int v = 0; v < dag.vertexCount(); ++v) {
    for (const auto &neighbor : dag.neighbors(v)) {
      inDegree[neighbor.to]++;
    }
  }

  // Add all nodes with inDegree 0 to the queue
  for (int v = 0; v < dag.vertexCount(); ++v) {
    if (inDegree[v] == 0) {
      zeroInQueue.push(v);
    }
  }

  // Kahn's algorithm for topological sorting (BFS approach)
  while (!zeroInQueue.empty()) {
    int top = zeroInQueue.front();
    zeroInQueue.pop();
    topoResult.push_back(top);
    for (const auto &neighbor : dag.neighbors(top)) {
      inDegree[neighbor.to]--;
      if (inDegree[neighbor.to] == 0) {
        zeroInQueue.push(neighbor.to);
      }
    }
}

  return topoResult;
}
