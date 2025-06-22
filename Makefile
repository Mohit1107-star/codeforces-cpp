# Makefile

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra
TARGET := out
SRC := $(FILE)

.PHONY: run clean

run:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
