// mainq1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Word_Stats.h"

int main(int argc, char* argv[]){
	
	char const* const fileName = argv[1]; /* should check that argc > 1 */
    FILE* file = fopen(fileName, "r"); /* should check the result */
    char line[256];

    char *word;
    int *psum, *pnum, num, sum;
    psum = &sum;
    pnum = &num;

    getWordStats(word, fileName, int *sum, int *num)
    while (fgets(line, sizeof(line), file)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        printf("%s", line); 
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */

    fclose(file);

    return 0;
}