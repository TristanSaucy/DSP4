CXX = g++
CXXFLAGS= -std=c++11 -g -Wall
main: main.o dataset.o montecarlo.o
	$(CXX) $(CXXFLAGS) -o $@ $^
