#ifndef REVENUEOPTIMIZER_H
#define REVENUEOPTIMIZER_H

#include "DAG.h"
#include "TopoSort.h"
#include <vector>

using namespace std;


struct RevenueResult {
    // F(Start)
    long long maxRevenue;
    // in path order, Start/End excluded          
    vector<int> clientIds;    
};

class RevenueOptimizer {
public:
    // Computes F for every vertex in reverse topological order,
    // records opt[v], then follows opt from Start to End.
    static RevenueResult optimize(const DAG& dag, 
              const std::vector<int>& topoOrder);
};

#endif // REVENUEOPTIMIZER_H
