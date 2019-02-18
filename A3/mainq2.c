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
	
	char const* const fileName = argv[1]; /* should check that argc > 1 */
    FILE* file = fopen(fileName, "r"); /* should check the result */

    char review[MAX_REVIEW_L], cin;
    int *psum, *pnum, num = 0, sum = 0, i = 0;
    psum = &sum;
    pnum = &num;

    printf("enter a review: ");
    
    char line[LINEL+1], word[WORDL+1];
    fgets(line, LINEL+1, stdin);
    line[strlen(line)-1] = '\0';

    char *strIn, *nextWord = line;

    strIn = line;
    while(nextWord){
        nextWord = next_word(strIn, word);
        i = 0;
        while(word[i]){
            printf("%c", word[i]);
            i++;
        }
        sum = 0;
        num = 0;
        getWordStats(word, file, psum, pnum);
	    printf("the sum is: %d\n", sum);
	    printf("%s appeared %d times\n", word, num);
	    printf("The average score for reviews containing %s is %lf\n", word, (double) sum/num);
        printf("\n");
        strIn = nextWord;
        strIn++;
    }
    /*
    while(cin != '\n'){
    	scanf("%c", &cin);
    	review[i] = cin;
    	i++;
    }
    */
    
    //getWordStats(word, file, psum, pnum);
    printf("the sum is: %d\n", sum);
    //printf("%s appeared %d times\n", word, num);
    //printf("The average score for reviews containing %s is %lf\n", word, (double) sum/num);
    fclose(file);

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