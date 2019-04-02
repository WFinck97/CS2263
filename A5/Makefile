CFLAGS = -Wall
test: graph.o main.o
	gcc -o test graph.o main.o
graph.o: graph.c
	gcc -c graph.c $(CFLAGS)
main.o: main.c
	gcc -c main.c $(CFLAGS)
clean:
	/bin/rm -f *.o test