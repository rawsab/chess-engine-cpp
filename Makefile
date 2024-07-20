CXX=g++
CXXFLAGS= -std=c++14 -Wall -g -MMD

EXEC= chess
CCFILES= $(wildcard*.cc)
DEPENDS= ${OBJECTS: .o = .d}
OBJECTS= ${ccfiles: .cc = .o}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${EXEC} ${OBJECTS} ${DEPENDS}
