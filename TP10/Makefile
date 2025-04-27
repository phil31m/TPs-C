CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

EXERCISES = ex1_maximum ex2_conteneur ex3_paire ex4_matrix

all: $(EXERCISES) run

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

run: $(EXERCISES)
	@echo "\n=== Exécution de tous les exercices ===\n"
	@for ex in $(EXERCISES); do \
		echo "=== $$ex ==="; \
		./$$ex; \
		echo ""; \
	done

clean:
	rm -f $(EXERCISES)

.PHONY: all clean run 