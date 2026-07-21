//Below steps are follwed to count the number of smaller elements to the right of each element in the array
//step 1: For each element in the array, we will check all the elements to its right
//step 2: If any element to the right is smaller than the current element, we will increment the count for that element
//step 3: Finally, we will print the count array which contains the number of smaller elements to the right for each element in the original array
//This is a brute force approach with time complexity of O(n^2) and 
//space complexity of O(n)
//this can be done via divide and conquer approach using merge sort to 
//achieve O(nlogn) time complexity and O(n) space complexity

#include <stdio.h>

int main()
{
    int nums[] = {5, 2, 6, 1};

    int n = 4;

    int count[4];

    int i, j;

    // Step 1: Check every element
    for(i = 0; i < n; i++)
    {
        count[i] = 0;

        // Step 2: Compare with elements on the right
        for(j = i + 1; j < n; j++)
        {
            if(nums[j] < nums[i])
            {
                count[i]++;
            }
        }
    }

    // Step 3: Print the result
    printf("Count Array:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", count[i]);
    }

    return 0;
}

// above code can be done merge sort with n log n complexity and n space complexity using divide and conquer approach
