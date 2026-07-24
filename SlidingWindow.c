// sliding window demo using c
#include <stdio.h>

int main()
{
    int arr[] = {2, 5, 1, 8, 2, 9, 1};

    int n = sizeof(arr) / sizeof(arr[0]);// calculating the size of the array

    int k = 3; // window size

    int currentSum = 0;
    int maxSum = 0;
    int startIndex = 0;

    // Step 1: Calculate first window sum
    for(int i = 0; i < k; i++)
    {
        currentSum += arr[i];
    }

    maxSum = currentSum;

    // Step 2: Slide the window
    for(int i = k; i < n; i++)
    {
        currentSum = currentSum - arr[i-k] + arr[i];

        if(currentSum > maxSum)
        {
            maxSum = currentSum;
            startIndex = i - k + 1;
        }
    }

    // Step 3: Display Result
    printf("Maximum Sum = %d\n\n", maxSum);

    printf("Subarray : ");

    for(int i = startIndex; i < startIndex + k; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}