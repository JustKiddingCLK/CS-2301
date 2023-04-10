    #include <stdio.h>

 int largestItem(int arr[], int n);

int main()
{
    int size;
    printf("How big is your array?\n");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Please enter your values:\n");
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The array is ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The largest value is %d\n", largestItem(arr, size));
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