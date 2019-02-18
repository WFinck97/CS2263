//Word_Stats.c

#include "Word_Stats.h"
#define MAX_LENGTH 80

char *strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;

  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }

  return str;
}

void getWordStats(char *word, FILE *f, int *sum, int *num){
	/* look through each line for 'word', only need to look for the first instance
	of the word. If found, add score to sum and num++. move to next line.
	*/
	int numLine = 0, i = 0;
	char line[1000];
	char _word_[MAX_LENGTH];
	_word_[0] = ' ';

	// adding space to front and back of the word to ensure the word is found
	// separately not within another word.
	while(word[i]){
		_word_[i+1] = word[i];
		i++;
	}
	_word_[i+1] = ' ';
	_word_[i+2] = '\0';
	
	printf("%s\n", _word_);


	//will need to make sure caps don't matter
    while (fgets(line, sizeof(line), f)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        numLine++;
        //printf("%s", line);
        if(strstr(strlwr(line), strlwr(_word_)) != NULL){
        	(*num)++;
        	//printf("match\n");
		}
    }

    // when checking a word should I add space to start and end to make sure 
    // im not finding the word withing a word?
    printf("number of lines: %d\n", numLine); 
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */
}