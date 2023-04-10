#include <stdio.h>
#include "register.h"

int main(void){

	int option = 0;
	char file[50];
	printf("Which program would you like to run:");
	printf(" (1) Calculate overall revenue or (2) Calculate register balance:");

	scanf("%d", &option);

	printf("Please enter an input file:\n");	
	scanf("%s", file);


	return 0;
}