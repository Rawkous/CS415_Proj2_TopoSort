/* Finding the optimal revenue (maximum rental)
Let F(vi) = maximum rent obtained through a path from vertex vi to End.
  Let the edges out of vertex vi be to the neighboring vertices vm1, vm2, ...., vmk.
  Note the weight of the edge from vertex vi to each of its neighbors is wi

To compute F(vi), we can find the maximum F value obtained from its neighbors and add wi to it.
  That is, define the recurrence F(vi) = wi + max { F(vm1), F(vm2), ..., F(vmk) }, F(End) = 0.

The goal is to compute F(Start) = the maximum rent obtained through a path from vertex Start to End.
*/
