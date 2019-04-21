#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * question2(char *s, int l);
int isDigit(char *s);

int main(int argc, char *argv[]){
	// char str[] = "one two three", *str2;
	// str2 = question2(str,3);
	// printf("str = %s\n", str);
	// printf("str2 = %s\n", str2);
	// str2 = question2(str+8, 7);
	// printf("str = %s\n", str);
	// printf("str2 = %s\n", str2);
	// return 0;

	int product;
	if(argc < 3){
		printf("ERROR incorrect number of parameters\n");
		return EXIT_FAILURE;
	}

	if(isDigit(argv[1])==0){
		printf("ERROR first parameters must be a single digit\n");
		return EXIT_FAILURE;
	}

	if(isDigit(argv[2])==0){
		printf("ERROR second parameters must be a single digit\n");
		return EXIT_FAILURE;
	}

	product = ((int)(*argv[1]-'0'))*((int)(*argv[2]-'0'));

	printf("%s * %s = %d\n", argv[1], argv[2], product);
	return 0;
}

char * question2(char *s, int l){
	for(int i = 0; *s && i < l; i++){
		*s = 'x';
		s++;
	}
	return s;
}

int isDigit(char *s){
	if(strlen(s) == 1 && s[0] >= '0' && s[0] <= '9')
		return 1;
	else
		return 0;
}