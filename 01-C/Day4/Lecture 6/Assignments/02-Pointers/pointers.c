/*This code is written by Marawan Ahmed*/
#include <stdio.h>


int main(){
	int x = 1;
	int y = 2;
	int z = 3;
	
	int *p = &x;
	int *q = &y;
	int *r = &z;
	
	printf("Swapping pointers\n");
	
	r = p; 
	p = q; 
	q = r; 

	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);

	printf("p = %p\n", p);
	printf("q = %p\n", q);
	printf("r = %p\n", r);

	printf("*p = %d\n", *p);
	printf("*q = %d\n", *q);
	printf("*r = %d\n", *r);
}