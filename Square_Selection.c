#include <stdio.h>

int main()
{
    int nums[] = {-4, -1, 0, 3, 10};
    int n = 5;

    int result[5];// for storing the squares of the elements

    int i, j, temp;

    // Step 1: Square every element
    for(i = 0; i < n; i++)
    {
        result[i] = nums[i] * nums[i];
    }

    // Step 2: Bubble Sort
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++) // here n-i-1 is used to avoid unnecessary comparisons of already sorted elements
        {
            if(result[j] > result[j + 1])
            {
                temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }

    // Step 3: Print the sorted squares
    printf("Sorted Squares:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }

    return 0;
}