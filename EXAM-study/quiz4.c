#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int useless(int *v, int sz, int flag){
	if(sz <= 0) return 0;
	return useless(v, sz - 1, -flag)+ flag*v[sz-1];
}

int useful(unsigned int a){
	if(a <= 0) return 0;
	return a % 2 + useful(a/2);
}
int main(){
	// question 1
	// char **list, word[20];
	// int nwords;
	// printf("enter number of words: ");
	// scanf("%d", &nwords);
	// list = malloc(nwords * sizeof(char *));
	// for(int i = 0; i < nwords; i++){
	// 	scanf("%s", word);
	// 	list[i] = malloc(strlen(word)+1);
	// 	strcpy(list[i], word);
	// }
	// for(int i = 0; i < nwords; i++){
	// 	printf("%s\n", list[i]);
	// 	free(list[i]);
	// }

	// free(list);
	// return 0;

	//question 2
	// char **list, word[20];
	// int nwords;
	// printf("Enter number of words: ");
	// scanf("%d", &nwords);
	// list = malloc(nwords * sizeof(char *));
	// for(int i = 0; i < nwords; i++){
	// 	scanf("%s", word);
	// 	list[i] = malloc(strlen(word)+1);
	// 	list[i] = word;
	// }
	// for(int i = 0; i < nwords; i++){
	// 	printf("%s\n", list[i]);
	// }
	// return 0;

	//question 3
	int list[] = {1, 2, 3, 4, 5};
	printf("useless = %d\n", useless(list, 5, -1));
	printf("useful = %d\n", useful(39));
	return 0;
}