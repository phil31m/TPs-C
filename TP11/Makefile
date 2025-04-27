CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: run_exercises

run_exercises: exercise1 exercise2 exercise3
	@echo "\nRunning exercise1:"
	./exercise1
	@echo "\nRunning exercise2:"
	./exercise2
	@echo "\nRunning exercise3:"
	./exercise3

exercise1: exercise1.cpp
	$(CXX) $(CXXFLAGS) -o exercise1 exercise1.cpp

exercise2: exercise2.cpp
	$(CXX) $(CXXFLAGS) -o exercise2 exercise2.cpp

exercise3: exercise3.cpp
	$(CXX) $(CXXFLAGS) -o exercise3 exercise3.cpp

clean:
	rm -f exercise1 exercise2 exercise3 