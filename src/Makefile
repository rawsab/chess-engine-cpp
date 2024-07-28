CXX = g++
CXXFLAGS = -std=c++14
EXEC = chess

SRCS = main.cc controller.cc human.cc board.cc view.cc textView.cc piece.cc
HEADERS = controller.h types.h player.h human.h board.h square.h make.h view.h textView.h square.h piece.h
OBJS = $(SRCS:.cc=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC)

.PHONY: all clean
