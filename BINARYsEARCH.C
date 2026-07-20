#include <stdio.h>

int main()
{
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int n = 6;
    int target = 91;

    int left = 0;
    int right = n - 1;
    int mid;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if(nums[mid] == target)
        {
            printf("Element found at index %d", mid);
            return 0;
        }
        else if(target < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("Element not found");

    return 0;
}