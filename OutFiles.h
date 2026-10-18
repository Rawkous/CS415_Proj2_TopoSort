/* File Builder: code should save the output in a file called "out" + input filename. For example,
if input filename is "data3.txt", output filename is "outdata3.txt".*/ 
#ifndef OUTFILES_H
#define OUTFILES_H

#include <cstddef>
#include <ostream>
#include <string>

#include "RevenueOptimizer.h"

class OutFiles {
public:
    // Writes the result block in the required format to any stream
    // (std::cout or a file), so the console and file always match.
    static void writeResult(std::ostream& out, std::size_t numClients,
                            const RevenueResult& result);

    // "testData/data3.txt" -> "outdata3.txt"
    static std::string outputFileName(const std::string& inputPath);

    // Writes the result to "out" + input filename.
    // Returns false if the file could not be created.
    static bool saveResult(const std::string& inputPath, std::size_t numClients,
                           const RevenueResult& result);
};

#endif // OUTFILES_H
