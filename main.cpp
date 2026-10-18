#include <cstdlib>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "fileReader.h"

using namespace std;

// Debug helper for displaying the records loaded from the input file.
void printRecords(const vector<ClientTuple>& records) {
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
    vector<ClientTuple> records;

    if (!reader.read(fileName, records)) {
        string testDataPath = "testData/" + fileName;
        if (fileName == testDataPath || !reader.read(testDataPath, records)) {
            cerr << "Could not read file: " << fileName << "\n";
            return EXIT_FAILURE;
        }
    }

    printRecords(records);
    return 0;
}
