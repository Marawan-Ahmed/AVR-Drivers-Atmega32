/*This code is written by Marawan Ahmed*/
#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"

#define SIZE 10

void sort(u32 *ptr);

int main(){
	u32 *v1 = (u32*) malloc(SIZE * sizeof(u32));
	
	for (u32 i = 0; i < SIZE; i++){
		printf("Please enter number %d in matrix: ", i+1);
		scanf("%d", v1 + i);
	}
	sort(v1);
	for (int i = 0; i < SIZE; i++){
		printf("%d ", *(v1 + i));
	}	
	
}

void sort(u32 *ptr){
	u32 i, j;
    u32 swapped;
	
    for (i = 0; i < SIZE - 1; i++) {
        swapped = 0;
        for (j = 0; j < SIZE - i - 1; j++) {
            if (*(ptr+j) > *(ptr + j + 1)) {
				int temp = *(ptr + j);
				*(ptr + j) = *(ptr + j + 1);
				*(ptr + j + 1) = temp;
                swapped = 1;
            }
        }
  
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == 0)
            break;
    }
}