#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define ITEMS 51

int main(int argc, char *argv[]){

    // allocate arrays to store 6 months of data
    int num_months = argc - 1;
    int month_data[ITEMS][num_months+1];
    float money[ITEMS][2];

    // initialize money and month_data to zeros
    for (int i = 0; i < 7; i ++)
    {
        for (int j = 0; j < ITEMS; j++){
            month_data[j][i] = 0;
        }
    }
    for (int i = 0; i < ITEMS; i++){
        money[i][0] = 0;
        money[i][1] = 0;
    }
 
    int new_item;
    float cost;

    //loop over all months
    for (int i = 0; i < argc - 1; i++)
    {
        FILE* f1;
        // open sales file
        f1 = fopen(argv[2], "r");
        if(f1 == NULL)
        {
            printf("Error");
            return 0;
        }
        // load sales data
        while(fscanf(f1, "%d %f", &new_item, &cost) > 0){
            month_data[new_item][i+1] = month_data[new_item][i+1] + 1;
            month_data[new_item][0] = new_item;
        }
        fclose(f1);

    } // end loop over months

    // load sales data
    FILE* f2 = fopen("Costs.txt", "r");
    float purchase;

    while(fscanf(f2, "%i %f %f", &new_item, &purchase, &cost) > 0){
        money[new_item][0] = purchase;
        money[new_item][1] = cost;
    }
    fclose(f2);
    float* costs = readIncome(ITEMS);
    float income[ITEMS] = {0};
    get_totals(ITEMS, num_months+1, month_data);
    get_profits(ITEMS, num_months+1, month_data, income, &cost);
    top_earner(ITEMS, num_months+1, month_data, income, &cost);
    free(costs);
}
