CFLAGS = -Wall
sentiment1: Word_Stats.o mainq1.o
	gcc -o sentiment1 Word_Stats.o mainq1.o
sentiment2: Word_Stats.o mainq2.o
	gcc -o sentiment2 Word_Stats.o mainq2.o
Word_Stats.o: Word_Stats.c
	gcc -c Word_Stats.c $(CFLAGS)
mainq1.o: mainq1.c
	gcc -c mainq1.c $(CFLAGS)
mainq2.o: mainq2.c
	gcc -c mainq2.c $(CFLAGS)
clean:
	/bin/rm -f *.o sentiment1 sentiment2