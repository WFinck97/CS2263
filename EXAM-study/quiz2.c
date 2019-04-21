#include<stdio.h>
#include<stdlib.h>

int main(){
	int a[] = {5, 25, 34, 54, 14, 22, 52, 91};
	int *p = &a[1], *q = &a[5];

	printf("q = %p, p = %p, q - p = %ld\n", q,p,q-p);
	return 0;
}