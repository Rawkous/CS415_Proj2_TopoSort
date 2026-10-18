
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic
TARGET := main
SOURCES := main.cpp FileReader.cpp OutFiles.cpp DAG.cpp TopoSort.cpp RevenueOptimizer.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) FileReader.h DAG.h OutFiles.h TopoSort.h RevenueOptimizer.h Client.h
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
