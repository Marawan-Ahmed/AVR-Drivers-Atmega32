#include <stdio.h>

int main(){
	int cls_1[10] = {55, 47, 89, 76, 44, 65, 71, 33, 75, 83};
	int cls_2[10] = {65, 57, 66, 32, 45, 85, 76, 67, 15, 68};
	int cls_3[10] = {47, 22, 58, 55, 73, 22, 61, 77, 40, 93};
	
	
	int passed = 0;
	int failed = 0;
	int max_grade = cls_1[0];
	int min_grade = cls_1[0];
	int average_grade = 0;
	
	for (int i = 0; i < 10; i++){
		if (cls_1[i] >= 50){
			passed++;
		}
		else{
			failed++;
		}
		
		if (max_grade > cls_1[i]){
			max_grade = cls_1[i];
		}
		if (min_grade < cls_1[i]){
			min_grade = cls_1[i];
		}	
		average_grade += cls_1[i];		
	}

	for (int i = 0; i < 10; i++){
		if (cls_2[i] >= 50){
			passed++;
		}
		else{
			failed++;
		}
		
		if (max_grade > cls_2[i]){
			max_grade = cls_2[i];
		}
		if (min_grade < cls_2[i]){
			min_grade = cls_2[i];
		}	
		average_grade += cls_2[i];		
	}	
	for (int i = 0; i < 10; i++){
		if (cls_3[i] >= 50){
			passed++;
		}
		else{
			failed++;
		}
		
		if (max_grade > cls_3[i]){
			max_grade = cls_3[i];
		}
		if (min_grade < cls_3[i]){
			min_grade = cls_3[i];
		}	
		average_grade += cls_3[i];		
	}

	average_grade /= 30;

	printf("Number of Passed Students = %d\n", passed);	
	printf("Number of Failed Students = %d\n", failed);
	printf("Max Grade = %d\n", max_grade);		
	printf("Min Grade = %d\n", min_grade);	
	printf("Average Grade = %d\n", average_grade);	
}	
	
	