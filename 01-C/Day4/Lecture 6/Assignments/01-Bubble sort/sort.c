/*This code is written by Marawan Ahmed*/
#include <stdio.h>
#define SIZE 10

void sort(int arr[]);

int main(){
	int v1[SIZE];
	
	for (int i = 0; i < SIZE; i++){
		printf("Please enter number %d in matrix 1: ", i+1);
		scanf("%d", &v1[i]);
	}
	sort(v1);
	for (int i = 0; i < SIZE; i++){
		printf("%d ", v1[i]);
	}	
	
}

void sort(int arr[]){
	int i, j;
    int swapped;
    for (i = 0; i < SIZE - 1; i++) {
        swapped = 0;
        for (j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
                swapped = 1;
            }
        }
  
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == 0)
            break;
    }
}