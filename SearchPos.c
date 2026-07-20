#include <stdio.h>

int main()
{
    int nums[] = {1, 3, 5, 6};
    int n = 4;
    int target = 6;

    int left = 0;
    int right = n - 1;
    int mid;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if(nums[mid] == target)
        {
            printf("Target found at index %d", mid);
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

    printf("Target not found.\n");
    printf("Insert Position = %d", left);

    return 0;
}