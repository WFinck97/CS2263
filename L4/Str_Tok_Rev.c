#include "Str_Tok_Rev.h"

char **stringToTokens(char *str, char *sep){
	char *strpt = str, *wordTok, *wordToken, *word;
	int numWords = 0, i = 0, len, validInput = 0;
	char cpyIn[80];

	len = strlen(str);
	// checking that there is an input
	if(len == 0){
		printf("please enter a sentence\n");
		exit(0);
	}
	else{
		for(i = 0; i < len; i++){
			if(strchr(sep, str[i]) == NULL){
			validInput = 1;
			}
		}
	}

	if(validInput == 0){
		printf("invalid input\n");
		exit(0);
	}

	// checking if input is valid
	strcpy(cpyIn, str);
	wordToken = strtok(cpyIn, sep);
	numWords++;

	while(wordToken != NULL){
		wordToken = strtok(NULL, sep);
		if(wordToken != NULL){
			numWords++;
		}
	}

	char **tokArray = malloc((numWords+1)*sizeof(char*));

	i = 0;
	wordTok = strtok(strpt, sep);
	len = strlen(wordTok);
	word = malloc(len*sizeof(char));
	strcpy(word,wordTok);
	reverse(word);
	tokArray[i] = word;
	i++;
	while(wordTok != NULL){
		wordTok = strtok(NULL, sep);
		if(wordTok != NULL){
			len = strlen(wordTok);
			word = malloc(len*sizeof(char));
			strcpy(word,wordTok);
			reverse(word);
			tokArray[i] = word;
			i++;
		}
	}
	tokArray[i] = NULL;
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
	int len, i, end;
	char temp;
	len = strlen(s);
	end = len - 1;
	for(i = 0; i <= len/2; i++){
		temp = s[i];
		s[i] = s[end];
		s[end] = temp;
		end--;
	}
}