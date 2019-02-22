// mainq1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Word_Stats.h"

#define MAX_STRING_LEN 80

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

    char word[MAX_STRING_LEN];
    int *psum, *pnum, num = 0, sum = 0;
    psum = &sum;
    pnum = &num;

    printf("enter a word: ");
    scanf("%s", word);


    getWordStats(word, file, psum, pnum);
    printf("%s appeared %d times\n", word, num);
    printf("The average score for reviews containing %s is %lf\n", word, (double) sum/num);
    fclose(file);

    return 0;

}