#include "OutFiles.h"

#include <fstream>

using namespace std;

void OutFiles::writeResult(ostream& out, size_t numClients,
                           const RevenueResult& result) {
    out << "There are " << numClients << " clients in this file\n\n";
    out << "Optimal revenue earned is " << result.maxRevenue << "\n";
    out << "Clients contributing to this optimal revenue: ";
    for (size_t i = 0; i < result.clientIds.size(); ++i) {
        if (i > 0) {
            out << ", ";
        }
        out << result.clientIds[i];
    }
    out << "\n";
}

string OutFiles::outputFileName(const string& inputPath) {
    const size_t slash = inputPath.find_last_of("/\\");
    const string baseName =
        (slash == string::npos) ? inputPath : inputPath.substr(slash + 1);
    return "out" + baseName;
}

bool OutFiles::saveResult(const string& inputPath, size_t numClients,
                          const RevenueResult& result) {
    ofstream outFile(outputFileName(inputPath));
    if (!outFile) {
        return false;
    }
    writeResult(outFile, numClients, result);
    return static_cast<bool>(outFile);
}
