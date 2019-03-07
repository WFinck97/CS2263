#include "Str_Tok_Rev.h"

char **stringToTokens(char *str, char *sep){
	char *strpt = str, *wordTok, *wordToken, *word;
	int numWords = 0, i = 0, len;
	char cpyIn[80];

	strcpy(cpyIn, str);
	if((wordToken = strtok(cpyIn, sep)) != NULL){
		numWords++;
	}
	else{
		printf("only one word was entered");
	}

	while(wordToken != NULL){
		wordToken = strtok(NULL, sep);
		if(wordToken != NULL){
			numWords++;
		}
	}

	char **tokArray = malloc((numWords+1)*sizeof(char*));

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