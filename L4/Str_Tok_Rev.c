#include "Str_Tok_Rev.h"

char **stringToTokens(char *str, char *sep){
	char *strpt = str, *wordTok, *wordToken;
	int numWords = 0, i = 0;
	char cpyIn[80];

	strcpy(cpyIn, str);
	if((wordToken = strtok(cpyIn, " ")) != NULL){
		numWords++;
	}
	else{
		printf("only one word was entered");
	}
	printf("%s\n", wordToken);

	while(wordToken != NULL){
		wordToken = strtok(NULL, " ");
		if(wordToken != NULL){
			numWords++;
			printf("%s\n", wordToken);
		}
	}

	printf("number of words: %d\n", numWords);

	char **tokArray = malloc(numWords*sizeof(char*));

	wordTok = strtok(strpt, " ");
	printf("%s\n", wordTok);
	tokArray[i] = wordTok;
	i++;
	while(wordTok != NULL){
		wordTok = strtok(NULL, " ");
		if(wordTok != NULL){
			printf("%s\n", wordTok);
			tokArray[i] = wordTok;
			i++;
		}
	}
	tokArray[i] = NULL;
	printf("number of words: %d\n", numWords);

	return tokArray;
}

void destroyTokens(char **tokenArray){

}

void reverse(char *s){

}