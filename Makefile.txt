CC = g++
CCFLAGS = -Wall -Wextra -std=c++17

TARGETS = exo1 exo2 exo3 exo4 exo5 exo6

all: $(TARGETS)

%: %.cpp
	$(CC) $(SpecifyLAGS) -o $@ $<



RM = rm -f
ifeq ($(OS),Windows_NT)
    RM = del /Q
endif

clean:
	$(RM) exo1.exe exo2.exe exo3.exe exo4.exe exo5.exe exo6.exe 2>nul


run: all
	@echo "Specify the exercise to run using: make run_exo EXO=<number>"

run_exo: exo$(EXO)
	@echo Running exercise exo$(EXO)
	./exo$(EXO)
