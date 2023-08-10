#include <stdio.h>

int min(int x1, int x2, int x3, int x4);
int max(int x1, int x2, int x3, int x4);

int main(){
	int x[4];
	int min_num, max_num;
	
	for (int i = 0; i < 4; i++){
		printf("Please enter number %d: ", i+1);
		scanf("%d", &x[i]);
	}
	
	min_num = min (x[0], x[1], x[2], x[3]);
	max_num = max (x[0], x[1], x[2], x[3]);
	
	printf("Max number is %d\n", max_num);
	printf("Min number is %d", min_num);

}

int min(int x1, int x2, int x3, int x4){
	int min_num = x1;
	
	if (min_num < x2){
		min_num = x2;
	}
	if (min_num < x3){
		min_num = x3;
	}
	if (min_num < x4){
		min_num = x4;
	}
	
	return min_num;
}
int max(int x1, int x2, int x3, int x4){
	int max_num = x1;
	
	if (max_num > x2){
		max_num = x2;
	}
	if (max_num > x3){
		max_num = x3;
	}
	if (max_num > x4){
		max_num = x4;
	}
	
	return max_num;
}