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
	// checking if input is valid
	if(validInput == 0){
		printf("invalid input\n");
		exit(0);
	}

	strcpy(cpyIn, str);
	wordToken = strtok(cpyIn, sep);
	numWords++;

	// counting the number of tokens in the string
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
	word = malloc((len+1)*sizeof(char));
	reverse(wordTok);
	strncpy(word,wordTok,len);
	tokArray[i] = word;
	i++;
	while(wordTok != NULL){
		wordTok = strtok(NULL, sep);
		if(wordTok != NULL){
			len = strlen(wordTok);
			word = malloc((len+1)*sizeof(char));
			reverse(wordTok);
			strncpy(word,wordTok,len);
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
	for(i = 0; i < len/2; i++){
		temp = s[i];
		s[i] = s[end];
		s[end] = temp;
		end--;
	}
}