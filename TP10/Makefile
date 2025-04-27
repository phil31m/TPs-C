CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

EXERCISES = ex1_maximum ex2_conteneur ex3_paire ex4_matrix

all: $(EXERCISES)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(EXERCISES)

.PHONY: all clean 