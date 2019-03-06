#include "Str_Tok_Rev.h"

char **stringToTokens(char *str, char *sep){
char *strpt = str, *wordToken;
int numWords = 0;
	
	if((wordToken = strtok(strpt, " ")) != NULL){
		numWords++;
	}
	else{
		printf("only one word was entered");
	}
	printf("%s\n", wordToken);

	while(wordToken != NULL){
		wordToken = strtok(NULL, " ");
		printf("%s\n", wordToken);
		numWords++;
	}

	printf("number of words: %d\n", numWords);
	return NULL;
}

void destroyTokens(char **tokenArray){

}

void reverse(char *s){

}