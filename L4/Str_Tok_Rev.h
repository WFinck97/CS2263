#ifndef Str_Tok_Rev_h
#define Str_Tok_Rev_h
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

/* stringToTokens takes a string and the separating characters. 
It separates the string into tokens using the separator characters.
An array of pointers is allocated on the heap with the size equivalent to
the number of tokens. Then, a deep copy of each token is made and the copy
is pointed to by the elements of the array of pointers. 
*/
char **stringToTokens(char *str, char *sep);char *strlwr(char *str);

/* destryTokens takes the address of the array of pointers and frees 
each deep copy as well as the array of pointers itself., removing them
from the heap.
*/
void destroyTokens(char **tokenArray);

/* reverse takes a string and reverses the elements of the string.
*/
void reverse(char *s);

#endif /* Str_Tok_Rev_h */