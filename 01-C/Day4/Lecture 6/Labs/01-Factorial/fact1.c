#include <stdio.h>

int fact(int n){
	int temp = 1;

	for (int i = n; i > 0; i--){
		temp*=i;
	}
	return temp;
}