/*Computing the optimal path
The optimal path from Start to End vertex can be computed very fast as follows:

Recall, F(vi) = wi + max { F(vm1), F(vm2), ..., F(vmk) },
Define, opti = arg (wi + max { F(vm1), F(vm2), ..., F(vmk) }),
where opti stores the vertex among the k vertices (m1, m2, ..., mk) 
that gave the MAX value in the above expression.

To find the optimal path, simply find the sequence of vertices that yielded the 
value F(Start) beginning from the vertex optStart. Then, iteratively, following 
the next vertex opti that maximizes F(vi) until the End vertex is reached.
*/
