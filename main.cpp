#include <cstdlib>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "FileReader.h"
#include "Client.h"
#include "DAG.h"

using namespace std;

// Debug helper for displaying the records loaded from the input file.
//I AM TESTING PUSH
void printRecords(const vector<tuple<int, int, int>>& records) {
    cout << "Records read: " << records.size() << "\n";

    for (size_t i = 0; i < records.size(); ++i) {
        const auto& [startDate, endDate, revenue] = records[i];
        cout << i + 1 << ": ("
             << startDate << ", "
             << endDate << ", "
             << revenue << ")\n";
    }
}

int main(int argc, char* argv[]) {
    string fileName;

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

    fileReader reader;
    vector<tuple<int, int, int>> records;

    if (!reader.read(fileName, records)) {
        string testDataPath = "testData/" + fileName;
        if (fileName == testDataPath || !reader.read(testDataPath, records)) {
            cerr << "Could not read file: " << fileName << "\n";
            return EXIT_FAILURE;
        }
    }

    printRecords(records);

    vector<Client> clients;
    for (size_t i = 0; i < records.size(); ++i) {
        int start = get<0>(records[i]);
        int end = get<1>(records[i]);
        long long revenue = get<2>(records[i]);
        clients.push_back(Client{static_cast<int>(i + 1), start, end, revenue});
    }

    DAG graph = DAG::constructDAG(clients);
    cout << "DAG contains " << graph.vertexCount() << " vertices.\n";
    


    return 0;
}
