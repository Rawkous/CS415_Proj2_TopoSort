#include <cstdlib>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "FileReader.h"
#include "Client.h"
#include "DAG.h"
#include "TopoSort.h"
#include "RevenueOptimizer.h"
#include "OutFiles.h"

using namespace std;

// Converts the raw (start, end, revenue) records into Clients.
// Client IDs are 1-based line numbers, so client k is DAG vertex k.
vector<Client> toClients(const vector<tuple<int, int, int>>& records) {
    vector<Client> clients;
    clients.reserve(records.size());
    for (size_t i = 0; i < records.size(); ++i) {
        const auto& [start, end, revenue] = records[i];
        clients.push_back(Client{static_cast<int>(i + 1), start, end,
                                 static_cast<long long>(revenue)});
    }
    return clients;
}

int main(int argc, char* argv[]) {
    string fileName;
    // 1. Read the input file name from command line or prompt the user.
    if (argc > 2) {
        cerr << "Usage: " << argv[0] << " [filename]\n";
        return EXIT_FAILURE;
    }

    if (argc == 2) {
        fileName = argv[1];
    } else {
        cout << "Enter the file from testData to read: ";
        if (!(cin >> fileName)) {
            cerr << "No filename was provided.\n";
            return EXIT_FAILURE;
        }
    }
    // 2. Read the file, falling back to the testData/ folder.
    fileReader reader;
    vector<tuple<int, int, int>> records;
    if (!reader.read(fileName, records)) {
        const string testDataPath = "testData/" + fileName;
        if (!reader.read(testDataPath, records)) {
            cerr << "Could not read file: " << fileName << "\n";
            return EXIT_FAILURE;
        }
    }
    const vector<Client> clients = toClients(records);

    // 3. Build the DAG, sort it, and find the optimal revenue.
    RevenueResult result{0, {}};
    if (!clients.empty()) {  // with no clients, Start has no path to End
        try {
            const DAG graph = DAG::constructDAG(clients);
            const vector<int> order = TopoSortQueue::topoSort(graph);
            result = RevenueOptimizer::optimize(graph, order);
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
            return EXIT_FAILURE;
        }
    }

    // 4. Print to the console and save to "out" + input filename.
    OutFiles::writeResult(cout, clients.size(), result);

    if (!OutFiles::saveResult(fileName, clients.size(), result)) {
        cerr << "Could not write output file: "
             << OutFiles::outputFileName(fileName) << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
