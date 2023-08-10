/*This code is written by Marawan Ahmed*/
#include <stdio.h>
int main(){
	int x = 10;
	
	printf("x before change is = %d\n", x);
	
	int *y = &x;
	*y = 20;
	
	printf("x after change is = %d", x);
}