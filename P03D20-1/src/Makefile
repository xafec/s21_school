CC = gcc 
CFLAGS = -Wall -Werror -Wextra

all: graph

graph: calculate.o functions.o graph.o shunting.o stacks.o
	$(CC) $(CFLAGS) calculate.o functions.o graph.o shunting.o stacks.o -o ../graph/graph

calculate.o: calculate.c stacks.h shunting.h functions.h
	$(CC) $(CFLAGS) -c calculate.c

functions.o: functions.c stacks.h functions.h
	$(CC) $(CFLAGS) -c functions.c

graph.o: graph.c stacks.h calculate.h shunting.h
	$(CC) $(CFLAGS) -c graph.c

shunting.o: shunting.c stacks.h shunting.h functions.h
	$(CC) $(CFLAGS) -c shunting.c

stacks.o: stacks.c stacks.h
	$(CC) $(CFLAGS) -c stacks.c

clean: 
	rm -f ../graph/graph *.o

rebuild: clean all