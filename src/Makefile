CXX = g++
CXXFLAGS = -std=c++14
EXEC = a3q1

SRCS = main.cc controller.cc
HEADERS = controller.h types.h player.h View.h human.h
OBJS = $(SRCS:.cc=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC)

.PHONY: all clean
