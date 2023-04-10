#include <stdio.h>
#include "register.h"

int main()
{    
	int option = 0;
	char file[50];

	printf("Which program would you like to run (1) Calculate overall revenue or (2) Calculate register balance\n");
	scanf("%d", &option);
	
	if(option == 0 || option > 2)
	{
		printf("This option is not valid.");
	}

	printf("Please enter an input file\n");
	scanf("%s",&file);

    FILE *f1;
    f1 = fopen(file, "r");
    if (f1 == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    if (option == 1)
    {
        float rev = overall_revenue(f1);
        printf("%.2f\n", rev);
    }
    else if (option == 2)
    {
        float bal = balance(f1);
        printf("%.2f\n", bal);
    }
    else
    {
        printf("Invalid program\n");
        return 1;
    }

    fclose(f1);
    return 0;
}