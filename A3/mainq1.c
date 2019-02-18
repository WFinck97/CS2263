// mainq1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Word_Stats.h"

#define MAX_STRING_LEN 80

int main(int argc, char* argv[]){
	
	char const* const fileName = argv[1]; /* should check that argc > 1 */
    FILE* file = fopen(fileName, "r"); /* should check the result */
    char line[256];

    char word[MAX_STRING_LEN];
    int *psum, *pnum, num = 0, sum = 0;
    psum = &sum;
    pnum = &num;

    printf("enter a word: ");
    scanf("%s", word);

    printf("%s\n", word);

    getWordStats(word, file, psum, pnum);
    printf("%d\n", num);
    fclose(file);

    return 0;

}