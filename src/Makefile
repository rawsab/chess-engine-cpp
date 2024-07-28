CXX = g++
CXXFLAGS = -std=c++14
EXEC = chess

SRCS = main.cc controller.cc human.cc board.cc
HEADERS = controller.h types.h player.h View.h human.h board.h square.h
OBJS = $(SRCS:.cc=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC)

.PHONY: all clean
