CFLAGS = -Wall
TestTokens: Str_Tok_Rev.o main.o
	gcc -o TestTokens Str_Tok_Rev.o main.o
Str_Tok_Rev.o: Str_Tok_Rev.c
	gcc -c -g -Og -std=gnu99 Str_Tok_Rev.c $(CFLAGS)
main.o: main.c
	gcc -c -g -Og -std=gnu99 main.c $(CFLAGS)
clean:
	/bin/rm -f *.o TestTokens