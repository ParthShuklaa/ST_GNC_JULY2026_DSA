// Step 1: Divide the array into two halves recursively.
// Step 2: Continue dividing until each sub-array contains only one element.
// Step 3: Merge the sorted sub-arrays.
// Step 4: During the merge process, whenever an element from the right sub-array
 //is placed before an element in the left sub-array, it indicates a smaller element to the right.
// Step 5: Count the number of such smaller elements and update the corresponding 
//index of the original array.
// Step 6: Continue merging until the complete array is sorted.
// Step 7: Return the count array.

#include <stdio.h>

#define MAX 100

// Structure to store value and its original index
typedef struct
{
    int value;
    int index;
} Node; // node is a structure that holds the value of an element and its original index in the array

Node arr[MAX];
Node temp[MAX];

int count[MAX];

// Merge two sorted halves and update counts
void merge(int left, int mid, int right) // a recursive function that merges two sorted halves of the array and updates the count of smaller elements to the right
{
    int i = left;
    int j = mid + 1;
    int k = left;

    int rightCount = 0;

    while(i <= mid && j <= right) 
    // here we are comparing the elements of the left and right halves of the array to merge them in sorted order
    {
        if(arr[j].value < arr[i].value)
        {
            temp[k++] = arr[j++];
            rightCount++; // for every element in the right half that is smaller than the current element in the left half, we increment the rightCount
        }
        else
        {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    // Copy remaining elements of left half
    while(i <= mid)
    {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of right half
    while(j <= right)
    {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for(i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

// Recursive Merge Sort
void mergeSort(int left, int right) // calling it aGain to sort the left and right halves of the array recursively and merge them while counting the smaller elements to the right
{
    if(left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(left, mid); // CALLING THE FUNCTION RECURSIVELY TO SORT THE LEFT HALF OF THE ARRAY
    mergeSort(mid + 1, right); // CALLING THE FUNCTION RECURSIVELY TO SORT THE RIGHT HALF OF THE ARRAY

    merge(left, mid, right); // MERGING THE TWO SORTED HALVES AND UPDATING THE COUNT OF SMALLER ELEMENTS TO THE RIGHT
}

int main()
{
    int nums[] = {5, 2, 6, 1};
    int n = 4;

    int i;

    // Initialize array with values and original indices
    for(i = 0; i < n; i++)
    {
        arr[i].value = nums[i];
        arr[i].index = i;
        count[i] = 0;
    }

    // Perform Merge Sort
    mergeSort(0, n - 1);

    // Print result
    printf("Count Array:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", count[i]);
    }

    return 0;
}
