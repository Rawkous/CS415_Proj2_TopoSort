
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic
TARGET := main
SOURCES := main.cpp FileReader.cpp DAG.cpp TopoSort.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) FileReader.h
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
