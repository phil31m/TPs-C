CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = cloud_simulator
SRCS = main.cpp Resource.cpp Container.cpp Pod.cpp Server.cpp KubernetesCluster.cpp Cloud_Util.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
