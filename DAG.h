/* Graph structure: Each CLient can be represented as a vertex.
Directed edges between clients indicate that there is no conflict
between the times they want the rental property. 
*/

/*A directed edge from vertex i to vertex j is created if and only if 
the end date of vertex i isless than or equal to start date of vertex j.
That is, if the data (start date, end date, amount willing to pay) for 
vertices i and j is given by (si, ei, revi) and (sj, ej, revj), respectively, 
then:  Edge(i —> j) iff ei<= sj

In addition, construct two special vertices Start and End with edges from them defined as:
There is an edge from vertex i to the End vertex if there is no outgoing edges from vertex i.
Mathematically, Edge(i —> end) iff ∄ j s.t. Edge(i—> j)
There is an edge from the Start vertex to vertex i if there is no incoming edges to vertex i.
Mathematically, Edge(start—> i) iff ∄ j s.t. Edge(j—>i)

Edge weights: each edge from ( i —> j) has a weight equal to the rental reward at vertex i. 
Mathematically, w(i—> j) = revi

Since the Start vertex has no rental reward, all edges 
outgoing from Start vertex have a weight equal to zero. 
Mathematically, w(Start—> i) = 0
*/
#ifndef DAG_H
#define DAG_H

#include "Client.h"
#include <vector>


// One directed, weighted edge in the graph in the adjacency list representation of the graph.
struct Edge {
    int to; // The destination vertex of the edge.
    long long weight; // The weight of the edge.
};

// Directed Acyclic Graph (DAG) class representing the graph structure of clients and their rental requests.


class DAG {
public:
    explicit DAG(int numVertices); // Constructor to initialize the DAG with a specified number of vertices.

    void addEdge(int from, int to, long long weight); // Method to add a directed edge from one vertex to another with a specified weight.

    int vertexCount() const; // Method to get the number of vertices in the DAG.

    const std::vector<Edge>& neighbors(int vertex) const; // Method to get the neighbors (outgoing edges) of a specified vertex.

    int inDegree(int vertex) const; // Method to get the in-degree (number of incoming edges) of a specified vertex.

private:
    int numVertices; // The number of vertices in the DAG.

    std::vector<std::vector<Edge>> adjList; // Adjacency list representation of the graph, where each vertex has a list of outgoing edges.

    std::vector<int> inDegrees; // Vector to store the in-degree of each vertex.
};


// Rental specific DAG
inline int startVertex(int numClients) {
    return 0; // The start vertex is represented by the index equal to the number of clients.
}
inline int endVertex(int numClients) {
    return numClients + 1; // The end vertex is represented by the index equal to the number of clients plus one.
}


// Function to construct the DAG from a list of clients. It creates edges based on the clients' rental requests and their time intervals.
DAG constructDAG(const std::vector<Client>& clients);


#endif // DAG_H
