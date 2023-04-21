#include <stdio.h>
#include <stdlib.h>
#include "data_functions.h"

int main(int argc, char* argv[]){

    if(argc<2){
        puts("Missing command line arguements\n");
    }
    else{
        int num_items = atoi(argv[1]);
        // inizalized the array
        float ARRAY[num_items];
        float* data_array = read_data(num_items);
        //open file
        FILE* f1 = fopen("data.txt","r");
        if (f1 != NULL){

            // load data
            for (int i=0;i<num_items;i++){
                fscanf(f1,"%f",&ARRAY[i]);       
            }

            // calculate the sum
            float sum = getSum(ARRAY, num_items);
            printf("The sum is %.3f\n", sum);
        }
        else{
            puts("Missing file\n");
        }
    }
    
}

