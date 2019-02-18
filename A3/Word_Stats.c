//Word_Stats.c

#include "Word_Stats.h"

void getWordStats(char *word, FILE *f, int *sum, int *num){
	/* look through each line for 'word', only need to look for the first instance
	of the word. If found, add score to sum and num++. move to next line.
	*/

	char line[256];

    while (fgets(line, sizeof(line), file)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        printf("%s", line); 
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */
	if(strstr(line, word)){

	}
}