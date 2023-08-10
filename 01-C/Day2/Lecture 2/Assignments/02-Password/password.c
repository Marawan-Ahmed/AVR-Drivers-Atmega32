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
			printf(user_name);
		}
		else{
			printf("Wrong Password");
		}
	}
	else{
		printf("Wrong ID");
	}
}