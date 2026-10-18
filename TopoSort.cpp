#include "TopoSort.h"

/*
Queue-based topological sort instructions

Use std::queue<int> readyVertices to hold vertices that currently have no
remaining prerequisites. Use std::vector<int> remainingInDegrees as a working
copy of the graph's in-degree values.

Suggested implementation shape:

    int vertexCount = graph.vertexCount();
    vector<int> remainingInDegrees(vertexCount);
    queue<int> readyVertices;
    vector<int> ordering;

    // Initialize the working in-degrees and queue.
    for (int vertex = 0; vertex < vertexCount; ++vertex) {
        remainingInDegrees[vertex] = graph.inDegree(vertex);
        if (remainingInDegrees[vertex] == 0) {
            readyVertices.push(vertex);
        }
    }

    // Repeatedly process vertices that are ready.
    while (!readyVertices.empty()) {
        int current = readyVertices.front();
        readyVertices.pop();
        ordering.push_back(current);

        for (const Edge& edge : graph.neighbors(current)) {
            --remainingInDegrees[edge.to];
            if (remainingInDegrees[edge.to] == 0) {
                readyVertices.push(edge.to);
            }
        }
    }

    // A valid DAG must place every vertex in the ordering. If not, a cycle
    // prevented one or more vertices from ever reaching in-degree zero.

Important details:
- Use edge.to for the destination vertex; edge.weight is irrelevant here.
- Decrement only the working copy, not graph's stored in-degree.
- The ordering contains graph indices, not Client IDs directly.
- Start should appear before client vertices, and End should appear after them.
- Include <queue> in this file if you implement the function here.
*/
