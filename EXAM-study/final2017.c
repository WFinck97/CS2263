#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 	QUESTION 3
int removeDup(int *a, int n, int maxVal){
	int occur[maxVal + 1];
	int newInd = 0;
	for(int i = 0; i < (maxVal + 1); i++){
		occur[i] = 0;
	}

	for(int i = 0; i < n; i++){
		if(occur[a[i]] == 0){
			occur[a[i]] = 1;
			a[newInd] = a[i];
			newInd++;
		}
	}

	return(newInd);
}

// QUESTION 5
int * mystery1(int *a, int b, int n){
	int *p = a;
	int *q = NULL;
	while((p - a) < n){
		if(*p == b)
			q = p;
		p++;
	}
	return q;
}

// QUESTION 6
void mystery2(char *s1, char *s2){
	char *p, *t;

	for(p = s1, t = s2; *p; p++, t++){
		*t = *p;
	}
	for(p = p - 1; (p - s1) >= 0; p--, t++){
		*t = *p;
	}
	*t = '\0';
}

// QUESTION 7
char *stringlastc(char *s, char c){
	char *out = NULL;

	char *cur = s;
	while(*cur){
		if(*cur == c){
			out = cur;
		}
		cur++;
	}

	return out;
}

// QUESTION 8
void reverse(char *string, int len){
	char tmp = string[0];
	if(len <= 0){
		return;
	}
	string[0] = string[len - 1];
	string[len - 1] = tmp;
	reverse(string + 1, len - 2);
}

// QUESTION 9
typedef struct person{
	char name[100];
	int age;
} Person;

Person * constructor(char *s, int a){
	Person p;
	p = malloc(sizeof(Person)); // is this all I need to add?
	strcpy(p.name, s);
	p.age = a;
	return &p;
}

// QUESTION 10
typedef struct node{
	int value;
	struct node *next;
} NodeT;

NodeT * deleteFromList(NodeT *first, int n){
	NodeT *cur = first, *prev = NULL;

	while(cur != NULL && cur->value != n){
		prev = cur;
		cur = cur->next;
	}
	if(cur != NULL){
		prev->next = cur->next;
		free(cur);
	}
	return first;

}

int main(int argc, char *argv[]){
	// QUESTION 3
	// int a[] = {1, 2, 1, 3, 2, 9, 6, 1};
	// int numDistinct;

	// numDistinct = removeDup(a, 8, 9);
	// for(int i = 0; i < numDistinct; i++){
	// 	printf("%d ", a[i]);
	// }
	// printf("\n");
	
	// QUESTION 4
	// int max = 0;
	// int numArg;
	// numArg = (int)(*argv[1] - '0'); 
	// int a[numArg];
	// for(int i = 0; i < numArg; i++){
	// 	scanf("%d", &a[i]);
	// 	if(a[i] > max){
	// 		max = a[i];
	// 	}
	// }
	// int numDistinct;

	// numDistinct = removeDup(a, numArg, max);
	// for(int i = 0; i < numDistinct; i++){
	// 	printf("%d ", a[i]);
	// }
	// printf("\n");

	// QUESTION 5
	// int array[] = {1, 6, 2, 3, 2};
	// printf("%d\n", mystery1(array, 2, 5) - array);

	// return 0;

	// QUESTION 6
	// char s2[] = "HelloDOGGO";
	// char s1[] = "Hello     ";
	// printf("%s\n", s2);
	// s1 = s2;
	// printf("%s\n", s2);
	// *(s2+3) = 'G';
	// printf("%s\n", s2);
	// mystery2("Hello", s2);
	// printf("%s\n", s2);

	// QUESTION 7
	// char *pointer, *in = "Hello";
	// pointer = stringlastc(in, 'H');
	// if(pointer != NULL){
	// 	printf("%c\n", *pointer);
	// 	printf("%d\n", pointer - in);
	// }

	// QUESTION 8
	char s[] = "dontiy";
	char *s1 = s+2;
	printf("%c\n", s1[-1]);
	printf("strlen(s) = %d\n", strlen(s));
	reverse(s, strlen(s));
	printf("%s\n",s);
	

	return 0;
}