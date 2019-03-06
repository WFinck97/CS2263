#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Str_Tok_Rev.h"

#define MAX_REVIEW_L 200
#define LINEL 80
#define WORDL 20

int main(){

	printf("enter a review:\n");
    
    char line[LINEL+1], word[WORDL+1];
    fgets(line, LINEL+1, stdin);
    line[strlen(line)-1] = '\0';

    char *strIn, *nextWord = line;

    strIn = line;
}