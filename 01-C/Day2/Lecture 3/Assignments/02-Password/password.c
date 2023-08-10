#include <stdio.h>
int id = 1234;
int password = 5555;
char *user_name = "Marawan";

int main(){
	int input_id, input_password;
	printf("Please enter ID: ");
	scanf("%d", &input_id);
	
	if(input_id == id){
		printf("Please enter Password: ");
		scanf("%d", &input_password);
		
		if(input_password == password){
			printf("Welcome ");
			printf(user_name);
		}
		else{
			int i;
			for(i = 0; i < 2; i++){
				printf("Try again: ");
				scanf("%d", &input_password);
				
				if(input_password == password){
					printf("Welcome ");
					printf(user_name);
					break;
				}				
			}
			if (i == 2){
				printf("No more tries");
			}

		}
	}
	else{
		printf("You are not registered");
	}
}