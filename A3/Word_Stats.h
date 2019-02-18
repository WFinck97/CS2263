#ifndef Word_Stats_h
#define Word_Stats_h
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* searches for the string word in the file f(a pointer returned by a call to fopen in main),
and computes the total score of reviews containing the word and the total number of reviews 
that contain the word. These two values arereturned by reference (sumandnum).
*/
void getWordStats(char *word, FILE *f, int *sum, int *num);

#endif /* Word_Stats_h */