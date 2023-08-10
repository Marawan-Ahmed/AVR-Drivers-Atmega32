#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "STD_Types.h"

typedef struct{
//	u8 id;
	u8 math;
	u8 language;
	u8 physics;
	u8 chemistry;
}student;

student class[10];

int main(){
	   time_t t;
	srand((unsigned) time(&t));

	for (int i = 0; i <= 10; i++){
		class[i].math = rand() % 50;
		class[i].language = rand() % 50;
		class[i].physics = rand() % 50;
		class[i].chemistry = rand() % 50;
	}
	u8 input_id;
	printf("Please enter id: ");
	scanf("%d", &input_id);
	if (input_id >= 10 || input_id < 0){
		printf("student ID isn't correct");
	}
	else{
		printf("Math grade = %d\n", class[input_id].math);
		printf("Language grade = %d\n", class[input_id].language);
		printf("Physics grade = %d\n", class[input_id].physics);
		printf("Chemistry grade = %d\n", class[input_id].chemistry);
	}
}