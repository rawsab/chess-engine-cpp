CXX = g++
CXXFLAGS = -std=c++14 -g -Wall
EXEC = chess

SRCS = main.cc controller.cc human.cc board.cc view.cc textView.cc piece.cc square.cc rook.cc pawn.cc types.cc knight.cc queen.cc
HEADERS = controller.h types.h player.h human.h board.h make.h view.h textView.h square.h piece.h rook.h pawn.h knight.h queen.h
OBJS = $(SRCS:.cc=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
