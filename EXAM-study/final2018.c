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

// QUESTION 8
void mystery2(int *v, int *w){
	if(w > v){
		int *p = v;
		int *xp = v + 1;
		while(xp <= w){
			if(*xp > *p) p = xp;
			xp++;
		}
		int tmp = *p;
		*p = *w;
		*w = tmp;
		mystery2(v,w-1);
	}
}

// QUESTION 9
void titleCase(char *str){
	int i = 0;
	*str = toupper(*str);
	while(*str){
		if(str[i] == ' '){
			*(str + 1) = toupper(*(str + 1));
		}
		str++;
	}
}

// QUESTION 11
typedef struct node{
	int value;
	struct node *next;
}	NodeT;

NodeT * deleteFromList(NodeT *first, int key){
	// if(first == NULL){
	// 	return(first);
	// }

	// if(first->value == key){
	// 	first = first->next;
	// 	return(first);
	// }

	// if(first->next->value == key){
	// 	first->next = first->next->next;
	// 	return(first);
	// }

	// return deleteFromList(first->next, key);
	if(first == NULL){
		return(first);
	}

	if(first->value == key){
		first = first->next;
		return(first);
	}

	NodeT *cur = first;

	while(cur->next != NULL || cur->value != key){
		if(cur->next->value == key){
			cur->next = cur->next->next;
			break;
		}
		cur = cur->next;
	}

	return(first);
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
	// printf("%d\n", mystery(10));

	//  QUESTION 8
	// int arr[5] = {4, 12, 8, -5, 9};
	// mystery2(arr, arr + 4);
	// for(int i = 0; i < 5; i++){
	// 	printf("%d ", arr[i]);
	// }

	// QUESTION 9
	// char title[] = "this is the title of the question";
	// titleCase(title);
	// printf("%s\n", title);

	// QUESTION 10


 	return 0;
 }