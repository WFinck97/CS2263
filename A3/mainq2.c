// mainq2.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Word_Stats.h"

#define MAX_REVIEW_L 200
#define LINEL 80
#define WORDL 20

char * next_word(char *str, char *word);

int main(int argc, char* argv[]){
	
	if(argc != 2){
		printf("please enter one file\n");
		return EXIT_FAILURE;
	}
	char const* const fileName = argv[1];
    FILE* file;
    if((file = fopen(fileName, "r")) == NULL){
    	printf("invalid file name\n");
    	return EXIT_FAILURE;
    }

    double revSum = 0, avg;
    int *psum, *pnum, num = 0, sum = 0, numWord = 0;
    psum = &sum;
    pnum = &num;

    printf("enter a review:\n");
    
    char line[LINEL+1], word[WORDL+1];
    fgets(line, LINEL+1, stdin);
    line[strlen(line)-1] = '\0';

    char *strIn, *nextWord = line;

    strIn = line;
    while(nextWord){
        nextWord = next_word(strIn, word);
        printf("%s\n", word);
        sum = 0;
        num = 0;
        getWordStats(word, file, psum, pnum);
	    printf("the sum is: %d\n", sum);
	    printf("%s appeared %d times\n", word, num);
	    if(num){
	    	avg = (double) sum / (double) num;
	    	numWord++;
	    }
	    else{
	    	avg = 0;
	    }
	    printf("The average score for reviews containing %s is %lf\n", word, avg);
        printf("\n");
        revSum = revSum + avg;
        
        strIn = nextWord;
        strIn++;
        fseek(file, 0, SEEK_SET);
    }
    

    fclose(file);
    printf("The review has an average value of %lf\n", revSum/((double) numWord));
    if((revSum/((double) numWord)) >= 2){
    	printf("Positive Sentiment\n");
    }

    else{
    	printf("Negative Sentiment\n");
    }
    return 0;
}

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