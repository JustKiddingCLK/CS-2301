#include <stdio.h>

int largestItem(int arr[], int n);

int main()
{
    FILE *f1;
    f1 = fopen("data.txt", "r");
    if (f1 == NULL)
    {
        printf("Error opening file.");
        return 1;
    }
    printf("How many values?\n");
    int n;
    scanf("%d", &n);
    int arr[n];
    
    int i;
    for(i = 0; i < n; i++)
    {
        fscanf(f1, "%d", &arr[i]);
    }
    fclose(f1);
    
    int largest = largestItem(arr, n);
    printf("The largest value is %d\n", largest);
    return 0;
}

int largestItem(int arr[], int n)
{
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++) 
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

