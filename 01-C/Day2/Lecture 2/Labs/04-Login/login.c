#include <stdio.h>


int main(){
	int x;
	printf("Please Enter Your ID: ");
	scanf("%d",&x);
	
	switch (x){
		case 1234: 
			printf("Ahmed");
			break;
		case 5678: 
			printf("Yousif");
			break;
		case 1145: 
			printf("Mina");
			break;	
		default:
			printf("Wrong ID");
			
	}
}