
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic
TARGET := main
SOURCES := main.cpp fileReader.cpp DAG.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) fileReader.h Client.h DAG.h
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
