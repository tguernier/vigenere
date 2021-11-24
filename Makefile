CXX=g++
CXXFLAGS=-Wall -g

all: vigenere.cpp main.cpp
	$(CXX) $(CXXFLAGS) vigenere.cpp main.cpp -o vigenere.out

.PHONY: clean

clean:
	rm -f *.out
