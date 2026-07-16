/*
=========================================================
        DYNAMIC ARRAY - PART 1
        Create, Display and Free Memory
=========================================================

Objective:
----------
Demonstrate how to create a Dynamic Array using malloc()
and release memory using free().

Topics Covered:
---------------
1. Pointers
2. Dynamic Memory Allocation
3. malloc()
4. free()
5. Functions
6. Arrays

Author : Classroom Demo
=========================================================
*/

#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------
// Function Prototypes
//-----------------------------------------------------
int* createArray(int size);
void inputArray(int arr[], int size);
void displayArray(int arr[], int size);
void releaseMemory(int *arr);

//-----------------------------------------------------
// Main Function
//-----------------------------------------------------
int main()
{
    int size;
    int *arr;

    printf("=====================================\n");
    printf("   DYNAMIC ARRAY USING MALLOC()\n");
    printf("=====================================\n");

    // STEP 1: Read array size
    printf("\nEnter Number of Elements : ");
    scanf("%d", &size);

    // Validate input
    if(size <= 0)
    {
        printf("\nInvalid Array Size!\n");
        return 0;
    }

    // STEP 2: Allocate memory
    arr = createArray(size);

    // STEP 3: Input array elements
    inputArray(arr, size);

    // STEP 4: Display array
    displayArray(arr, size);

    // STEP 5: Release memory
    releaseMemory(arr);

    printf("\nProgram Executed Successfully.\n");

    return 0;
}

//-----------------------------------------------------
// Function : createArray()
// Purpose  : Allocate memory dynamically
//-----------------------------------------------------
int* createArray(int size)
{
    int *ptr;
    //only pointers can be used to allocate memory dynamically in C/C++
    
    // Allocate memory
    ptr = (int *)malloc(size * sizeof(int));
    //size * sizeof(int) is used to allocate memory for the array of integers. It calculates the total number of bytes needed for the array based on the size and the size of an integer.

    // Check allocation
    if(ptr == NULL)
    {
        printf("\nMemory Allocation Failed!\n");
        exit(0);
    }

    printf("\nMemory Allocated Successfully.\n");

    return ptr;
}

//-----------------------------------------------------
// Function : inputArray()
// Purpose  : Read array elements
//-----------------------------------------------------
void inputArray(int arr[], int size)
{
    printf("\nEnter %d Elements\n", size);

    for(int i = 0; i < size; i++)
    {
        printf("Element [%d] : ", i);
        scanf("%d", &arr[i]);
    }
}

//-----------------------------------------------------
// Function : displayArray()
// Purpose  : Display array elements
//-----------------------------------------------------
void displayArray(int arr[], int size)
{
    printf("\n=====================================\n");
    printf("Array Elements\n");
    printf("=====================================\n");

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // Time Complexity
    printf("\nTime Complexity : O(n)\n");
}

//-----------------------------------------------------
// Function : releaseMemory()
// Purpose  : Free dynamically allocated memory
//-----------------------------------------------------
void releaseMemory(int *arr)
{
    free(arr);

    printf("\nMemory Released Successfully.");

    // Good Practice
    arr = NULL;
}