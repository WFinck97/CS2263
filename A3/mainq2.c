// mainq2.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Word_Stats.h"

#define MAX_REVIEW_L 200

int main(int argc, char* argv[]){
	
	char const* const fileName = argv[1]; /* should check that argc > 1 */
    FILE* file = fopen(fileName, "r"); /* should check the result */

    char review[MAX_REVIEW_L], cin;
    int *psum, *pnum, num = 0, sum = 0, i = 0;
    psum = &sum;
    pnum = &num;

    printf("enter a review: ");
    while(cin != '\n'){
    	scanf("%c", &cin);
    	review[i] = cin;
    	i++;
    }

    review[i-1] = '\0';

    printf("%s\n", review);
    //getWordStats(word, file, psum, pnum);
    printf("the sum is: %d\n", sum);
    //printf("%s appeared %d times\n", word, num);
    //printf("The average score for reviews containing %s is %lf\n", word, (double) sum/num);
    fclose(file);

    return 0;

}