#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "register.h"

int main(int argc, char *argv[])
{    
	int option = 0;
	char *in_file;
    char *out_file;
    char *out_mode;
    int item = 0;

    if(argc < 3)
    {
        printf("Error!\n");
        return 1;
    }

    option = atoi(argv[1]);
    if(option == 0 || option > 3)
    {
        printf("Invalid Option!\n");
        return 1;
    }

    in_file = argv[2];
    out_file = argv[3];
    
    FILE *f1;
    f1 = fopen(in_file, "r");
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
    else if (option == 3)
    {
        if(argc < 6)
        {
            printf("Not enough command line arguements\n");
            return 1;
        }
        if(out_file == NULL)
        {
        printf("Error opening output file.\n");
        return 1;
        }
        out_mode = argv[4];
        item = atoi(argv[5]);

        FILE *f2;
        int tal = tally(f1, item);

        if(strcmp(out_mode, "o") == 0)
        {
            f2 = fopen(out_file, "w");
            fprintf(f2, "%d%d\n", item, tal);
        }
        else if(strcmp(out_mode, "a") == 0)
        {
            f2 = fopen(out_file, "a");
            fprintf(f2, "%d%d\n", item, tal);
        }
        fclose(f2);
    }
    fclose(f1);
    return 0;
}