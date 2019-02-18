//Word_Stats.c

#include "Word_Stats.h"

void getWordStats(char *word, FILE *f, int *sum, int *num){
	/* look through each line for 'word', only need to look for the first instance
	of the word. If found, add score to sum and num++. move to next line.
	*/
	int numLine = 0;
	char line[1000];

	//will need to make sure caps don't matter
    while (fgets(line, sizeof(line), f)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        numLine++;
        printf("%s", line);
        if(strstr(line, word) != NULL){
        	(*num)++;
        	printf("match\n");
		}
    }

    // when checking a word should I add space to start and end to make sure 
    // im not finding the word withing a word?
    printf("%d\n", numLine); 
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */
}