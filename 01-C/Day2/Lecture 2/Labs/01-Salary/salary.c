#include <stdio.h>


int main(){
	int hrs = 0;
	int salary = 0;
	printf("Please Enter Your working hours: ");
	scanf("%d",&hrs);
	
	salary = hrs * 50;
	
	if (hrs < 40){
		salary *= 0.9;
	}
	
	printf("Your Salary is %d\n", salary);

}