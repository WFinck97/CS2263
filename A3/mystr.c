//mystr.c

#include "mystr.h"

char * next_word(char *str, char *word){
	char *strpt;
	strpt = str;
	while(*strpt != '\0'){
		if((*strpt == ' ' ) && (strpt > str)){
			
			*word = '\0';

			// if there is a space at the end of the last word
			if(*(strpt+1) == '\0'){
				return(NULL);
			}
			else{
				return(strpt);	
			}
			
		}
		*word = *strpt;
		word++;
		strpt++;
	}
	*word = '\0';
	return(NULL);
}

void remove_dup_blanks(char *str){
	char *strpt;
	int i = 0;
	strpt = str;

	while(*strpt != '\0'){
		if((*strpt == ' ') && (*(strpt - 1) == ' ')){}
		else{
			str[i] = *strpt;
			i++;
		}
		strpt++;
	}
	str[i] = '\0';
}