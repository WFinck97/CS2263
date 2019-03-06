#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Str_Tok_Rev.h"

#define MAX_SENTENCE_L 200
#define LINEL 80
#define WORDL 20

int main(){

	printf("enter sentence:\n");
    
    char line[LINEL+1];
    fgets(line, LINEL+1, stdin);
    line[strlen(line)-1] = '\0';

    char *strIn;

    strIn = line;

    printf("%s\n", strIn);

    char **tokenArray = stringToTokens(strIn, ", ");
    return 0;
}