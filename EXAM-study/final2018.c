#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// QUESTION 4
int is_palindrome(char *str, int len){
	if(len <= 1){
		return 1;
	}
	if(str[0] == str[len - 1]){
		return is_palindrome(str + 1, len - 2);
	}
	else{
		return 0;
	}
}

// QUESTION 5
char *my_cat(const char *str1, const char *str2){
	int len = strlen(str1) + strlen(str2);
	char *newstr;
	newstr = malloc(len * sizeof(char));
	for(int i = 0; i < strlen(str1); i++){
		newstr[i] = str1[i];
	}

	for(int i = 0; i < strlen(str2); i++){
		newstr[strlen(str1) + i] = str2[i];
	}

	newstr[len] = '\0';
	return newstr;
}

// QUESTION 7
int mystery(int n){
	if(n <= 0) return 1;
	else return 2 * mystery(n - 1);
}

int main(int argc, char *argv[]){
 	// question 2
 	// int i = 5, *pi, **ppi;

 	// pi = &i;
 	// ppi = &pi;
 	//ppi = &&i;
 	// **ppi = 25;
 	// pi = *ppi;
 	//ppi = pi;
 	// return 0;

 	// QUESTION 4

 	// char word[] = "maddam";
 	// printf("%s palindrome = %d\n", word, is_palindrome(word,strlen(word)));

	// QUESTION 5
	// char *st1, *res, word1[20];
	// res = "";

	// while(scanf("%s", word1) == 1){
	// 	st1 = my_cat(res, word1);
	// what do I put here?
	// 	res = st1;
	// }

	// printf("The result is: %s\n", res);
	// free(res);
 	
	// QUESTION 6
	// if(argc < 3){
	// 	printf("ERROR incorrect number of parameters\n");
	// 	return EXIT_FAILURE;
	// }

	// if(strlen(argv[1]) != 1 || argv[1][0] < '0' || argv[1][0] > '9'){
	// 	printf("ERROR first parameters must be a single digit\n");
	// 	return EXIT_FAILURE;
	// }

	// if(strlen(argv[2]) != 1 || argv[2][0] < 'A' || argv[2][0] > 'C'){
	// 	printf("ERROR second parameters must be A, B, or C\n");
	// }

	// QUESTION 7
	printf("%d\n", mystery(10));

 	return 0;
 }