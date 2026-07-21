// mergeSort.c steps 
// Step 1: Divide the array into two halves
// Step 2: Recursively sort both halves
// Step 3: Merge the sorted halves
//Step 4: Print the sorted array
 // so for achiving(O)nlogn time /space coplexity we use merge sort algorithm which is a divide and conquer algorithm using recusion and merging the sorted arrays to get the final sorted array

#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;

    int n1 = mid - left + 1; // this help in calculating the size of the left sub-array
    int n2 = right - mid; // this represents the size of the right sub-array

    int L[n1], R[n2]; // create temporary arrays to hold the left and right sub-arrays

    // Copy left sub-array
    for(i = 0; i < n1; i++) // if the left sub-array has n1 elements, we copy them into L
        L[i] = arr[left + i];

    // Copy right sub-array
    for(j = 0; j < n2; j++) // if the right sub-array has n2 elements, we copy them into R
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    // Merge the two sorted arrays
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left array
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of right array
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) // recursive function to implement merge sort
{
    if(left < right) // if the left index is less than the right index, we proceed with sorting
    {
        int mid = (left + right) / 2;

        // Sort left half by passing the left and mid indices to the mergeSort function
        mergeSort(arr, left, mid);

        // Sort right half by passing the mid + 1 and right indices to the mergeSort function
        mergeSort(arr, mid + 1, right);

        // Merge both halves by passing the left, mid, and right indices to the merge function
        merge(arr, left, mid, right);
    }
}

int main()
{
    int nums[] = {5,2,3,1};

    int n = 4;

    int i;

    mergeSort(nums, 0, n - 1);

    printf("Sorted Array:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}