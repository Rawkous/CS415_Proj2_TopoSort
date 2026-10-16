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
