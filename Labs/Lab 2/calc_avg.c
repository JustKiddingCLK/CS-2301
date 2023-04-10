#include <stdio.h>
#include <stdlib.h>

float get_average(int size);
// New prototype
// float get_average(int size, FILE* f1);

int main(int argc, char *argv[])
{
    printf("Hi\n");                
    int numVals = atoi(argv[1]);    // store number of data values
    FILE* f1 = fopen(argv[2], "r");
    
    float thisAv = get_average(numVals, f1);
    printf("Your average is %6.2f\n", thisAv);

    fclose(f1);

}

float get_average(int size, FILE* f1){
    printf("Input values\n");
    float total = 0;
    float data;
    for (int i = 0; i < size; i++){
        scanf("%f", &data);
        total = total + data;
    }
    return total/(float)size;
}