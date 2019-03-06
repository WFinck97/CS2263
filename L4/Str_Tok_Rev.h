#ifndef Str_Tok_Rev_h
#define Str_Tok_Rev_h
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

/* description of the function here
*/
char **stringToTokens(char *str, char *sep);char *strlwr(char *str);

/* description of the function here
*/
void destroyTokens(char **tokenArray);

/* description of the function here
*/
void reverse(char *s);

#endif /* Str_Tok_Rev_h */