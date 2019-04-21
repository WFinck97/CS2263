#include<stdio.h>
#include<stdlib.h>
int sum(int n);
int main(){
	// int a = 33, b= 40;
	// int r = scanf("%d %d", &a, &b);

	// printf("r = %d\na = %d\n b = %d\n", r, a, b);

	int in, s;
	scanf("%d", &in);
	s = sum(in);
	printf("the sum of the numbers is: %d\n", s);
	return 0;
}

int sum(int n){
	int rem, quo, dec = 10, sum = 0;

	while(quo != 0){
		quo = n/dec;
		rem = n%dec;
		sum = sum + rem;
		n = quo;
	}
	return sum;
}