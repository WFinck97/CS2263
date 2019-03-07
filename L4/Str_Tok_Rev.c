#include "Str_Tok_Rev.h"

char **stringToTokens(char *str, char *sep){
	char *strpt = str, *wordTok, *wordToken, *word;
	int numWords = 0, i = 0, len;
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

	char **tokArray = malloc((numWords+1)*sizeof(char*));

	wordTok = strtok(strpt, " ");
	len = strlen(wordTok);
	word = malloc(len*sizeof(char));
	strcpy(word,wordTok);
	printf("%s\n", word);

	tokArray[i] = word;
	i++;
	while(wordTok != NULL){
		wordTok = strtok(NULL, " ");
		if(wordTok != NULL){
			len = strlen(wordTok);
			word = malloc(len*sizeof(char));
			strcpy(word,wordTok);
			printf("%s\n", word);
			tokArray[i] = word;
			i++;
		}
	}
	tokArray[i] = NULL;
	printf("number of words: %d\n", numWords);

	return tokArray;
}

void destroyTokens(char **tokenArray){
	int i = 0;
	while(tokenArray[i] != NULL){
    	free(tokenArray[i]);
    	i++;
    }
    free(tokenArray);
}

void reverse(char *s){
	int len;
	len = strlen(s);
}