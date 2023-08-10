#include <stdio.h>

int main(){
	int opcode, x1, x2;
	printf("Please enter operation ID: ");
	scanf("%d", &opcode);
	
	switch(opcode){
		case 1:
			printf("Please enter first number: ");
			scanf("%d", &x1);
			printf("Please enter second number: ");
			scanf("%d", &x2);
			printf("a + b = %d", x1+x2);
			break;
		case 2:
			printf("Please enter first number: ");
			scanf("%d", &x1);
			printf("Please enter second number: ");
			scanf("%d", &x2);
			printf("a - b = %d", x1-x2);
			break;		
		case 3:
			printf("Please enter first number: ");
			scanf("%d", &x1);
			printf("Please enter second number: ");
			scanf("%d", &x2);
			printf("a * b = %d", x1*x2);
			break;
		case 4:
			printf("Please enter first number: ");
			scanf("%d", &x1);
			printf("Please enter second number: ");
			scanf("%d", &x2);
			printf("a / b = %d", x1/x2);
			break;
		case 5:
			printf("Please enter first number: ");
			scanf("%d", &x1);
			printf("Please enter second number: ");
			scanf("%d", &x2);
			printf("a & b = %d", x1&x2);
			break;			
		case 6:
			printf("Please enter first number: ");
			scanf("%d", &x1);
			printf("Please enter second number: ");
			scanf("%d", &x2);
			printf("a | b = %d", x1|x2);
			break;	
		case 7:
			printf("Please enter number: ");
			scanf("%d", &x1);
			printf("~a = %d", ~x1);
			break;	
		case 8:
			printf("Please enter first number: ");
			scanf("%d", &x1);
			printf("Please enter second number: ");
			scanf("%d", &x2);
			printf("a ^ b = %d", x1^x2);
			break;
		case 9:
			printf("Please enter first number: ");
			scanf("%d", &x1);
			printf("Please enter second number: ");
			scanf("%d", &x2);
			printf("a % b = %d", x1%x2);
			break;
		case 10:
			printf("Please enter number: ");
			scanf("%d", &x1);
			printf("a++ = %d", x1++);
			break;
		case 11:
			printf("Please enter number: ");
			scanf("%d", &x1);
			printf("a-- = %d", x1--);
			break;		
		default:	
			printf("Wrong ID");
	}

}