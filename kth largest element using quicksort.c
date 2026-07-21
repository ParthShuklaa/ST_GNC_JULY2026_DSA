#include <stdio.h>

void swap(int *a, int *b) // a recursive function that swaps the values of two integers using pointers
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) // recursive function that partitions the array into two halves based on a pivot element and returns the index of the pivot after partitioning
//here high n low are the indices of the sub-array that we want to partition, and arr is the array that we want to sort
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high) // here we are implementing the quick sort algorithm recursively to sort the array in ascending order
{
    if(low < high)
    {
        int pi = partition(arr, low, high); // calling the partition function to get the index of the pivot element after partitioning the array

        quickSort(arr, low, pi - 1); // calling the quickSort function recursively to sort the left half of the array
        quickSort(arr, pi + 1, high); // calling the quickSort function recursively to sort the right half of the array
    }
}

int main()
{
    int nums[] = {3,2,1,5,6,4};

    int n = 6;

    int k = 2;

    quickSort(nums, 0, n - 1);

    printf("Sorted Array:\n");

    for(int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    printf("\n\n%dth Largest Element = %d", k, nums[n-k]); // here we are printing the kth largest element in the sorted array by accessing the element at index n-k, where n is the size of the array and k is the position of the largest element we want to find

    return 0;
}
