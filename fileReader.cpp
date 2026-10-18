#include "fileReader.h"

#include <fstream>

using namespace std;

bool fileReader::read(const string& fileName,
                      vector<ClientTuple>& clients) const {
    ifstream input(fileName);
    if (!input) {
        return false;
    }

    clients.clear();

    int startDate;
    int endDate;
    int revenue;
    while (input >> startDate >> endDate >> revenue) {
        clients.emplace_back(startDate, endDate, revenue);
    }

    // A partial final record is invalid, while an empty file is valid.
    return input.eof();
}
