#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <tuple>
#include <vector>

using namespace std;

using ClientTuple = tuple<int, int, int>;

class fileReader {
public:
    // Reads start date, end date, and revenue triples from fileName.
    // Returns false if the file cannot be opened or contains incomplete data.
    bool read(const string& fileName,
              vector<ClientTuple>& clients) const;
};

using FileReader = fileReader;

#endif
