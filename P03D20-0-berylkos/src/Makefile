cc=gcc
flags=-Wall -Wextra -Werror

all: graph

graph: graph.o function.o
	$(cc) graph.o function.o -o graph
graph.o: graph.c
	$(cc) $(flags) -c graph.c
function.o: function.c
	$(cc) $(flags) -c function.c
clean:
	rm -f *.o
	rm -f ../build/*
	clear
rebuild: clean all
