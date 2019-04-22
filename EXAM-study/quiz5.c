#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int num;
	int *v;
	char *name;
	struct node *next;
} Node;

int main(){
	int i = 5;
	int *rr;
	Node *nd = malloc(sizeof(Node));
	Node test;

	*(test.v) = 23;
	*rr = 23;
	return 0;
}