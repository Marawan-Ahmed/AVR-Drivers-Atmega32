#include <stdio.h>
#include "STD_Types.h"

typedef struct{
	u16 salary;
	u16 bonus;
	u16 deduction;
}employee;

int main(){
	employee ahmed, waleed, amr;
	
	printf("Please enter Ahmed Salary: ");
	scanf("%d", &ahmed.salary);
	printf("Please enter Ahmed Bonus: ");
	scanf("%d", &ahmed.bonus);
	printf("Please enter Ahmed Deduction: ");
	scanf("%d", &ahmed.deduction);
	
	printf("Please enter Waleed Salary: ");
	scanf("%d", &waleed.salary);
	printf("Please enter Waleed Bonus: ");
	scanf("%d", &waleed.bonus);
	printf("Please enter Waleed Deduction: ");
	scanf("%d", &waleed.deduction);
	
	printf("Please enter Amr Salary: ");
	scanf("%d", &amr.salary);
	printf("Please enter Amr Bonus: ");
	scanf("%d", &amr.bonus);
	printf("Please enter Amr Deduction: ");
	scanf("%d", &amr.deduction);	
	
	u16 total_value = ahmed.salary + waleed.salary + amr.salary;
	total_value += ahmed.bonus + waleed.bonus + amr.bonus;
	total_value -= ahmed.deduction + waleed.deduction + amr.deduction;
	
	printf("Total Value Needed is %d", total_value);
}
