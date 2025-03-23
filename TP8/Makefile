CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = movie_tracker
SRCS = main.cpp Movie.cpp Movies.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) 