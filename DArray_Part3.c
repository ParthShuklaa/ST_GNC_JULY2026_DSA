/*
============================================================
        DYNAMIC ARRAY - PART 3
      realloc() | Search | Bubble Sort
============================================================

Operations
----------
1. Display Array
2. Add New Element (Auto Resize)
3. Linear Search
4. Bubble Sort
5. Show Capacity
6. Exit

Topics Covered
--------------
✓ malloc()
✓ realloc()
✓ free()
✓ Dynamic Arrays
✓ Linear Search
✓ Bubble Sort

============================================================
*/

#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void displayArray(int arr[], int size);
void addElement(int **arr, int *size, int *capacity);
void linearSearch(int arr[], int size);
void bubbleSort(int arr[], int size);

int main()
{
    int *arr;
    int size;
    int capacity;
    int choice;

    printf("=========================================\n");
    printf(" Dynamic Array using realloc()\n");
    printf("=========================================\n");

    printf("Enter Initial Capacity : ");
    scanf("%d", &capacity);

    if(capacity <= 0)
    {
        printf("Invalid Capacity!\n");
        return 0;
    }

    arr = (int *)malloc(capacity * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return 0;
    }

    printf("Enter Number of Initial Elements : ");
    scanf("%d", &size);

    if(size > capacity)
    {
        printf("Size cannot be greater than Capacity.\n");
        free(arr);
        return 0;
    }

    printf("\nEnter Elements\n");

    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n==============================\n");
        printf("1. Display Array\n");
        printf("2. Add Element\n");
        printf("3. Linear Search\n");
        printf("4. Bubble Sort\n");
        printf("5. Show Capacity\n");
        printf("6. Exit\n");

        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayArray(arr, size);
                break;

            case 2:
                addElement(&arr, &size, &capacity);
                break;

            case 3:
                linearSearch(arr, size);
                break;

            case 4:
                bubbleSort(arr, size);
                printf("Array Sorted Successfully.\n");
                break;

            case 5:
                printf("\nCurrent Size     : %d\n", size);
                printf("Current Capacity : %d\n", capacity);
                break;

            case 6:
                free(arr);
                printf("Memory Released Successfully.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}

//-----------------------------------------------------
// Display Array
//-----------------------------------------------------
void displayArray(int arr[], int size)
{
    printf("\nArray Elements:\n");

    if(size == 0)
    {
        printf("Array is Empty.\n");
        return;
    }

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nTime Complexity : O(n)\n");
}

//-----------------------------------------------------
// Add Element using realloc()
//-----------------------------------------------------
void addElement(int **arr, int *size, int *capacity)
{
    int value;

    printf("Enter New Element : ");
    scanf("%d", &value);

    // Resize if array is full
    if(*size == *capacity)
    {
        *capacity = (*capacity) * 2;

        *arr = (int *)realloc(*arr, (*capacity) * sizeof(int));

        if(*arr == NULL)
        {
            printf("Memory Reallocation Failed!\n");
            exit(0);
        }

        printf("Array Resized Successfully.\n");
        printf("New Capacity = %d\n", *capacity);
    }

    (*arr)[*size] = value;
    (*size)++;

    printf("Element Added Successfully.\n");
    printf("Time Complexity : O(1) Average, O(n) During Resize\n");
}

//-----------------------------------------------------
// Linear Search
//-----------------------------------------------------
void linearSearch(int arr[], int size)
{
    int key;
    int found = 0;

    printf("Enter Element to Search : ");
    scanf("%d", &key);

    for(int i = 0; i < size; i++)
    {
        if(arr[i] == key)
        {
            printf("Element Found at Index %d\n", i);
            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("Element Not Found.\n");
    }

    printf("Time Complexity : O(n)\n");
}

//-----------------------------------------------------
// Bubble Sort
//-----------------------------------------------------
void bubbleSort(int arr[], int size)
{
    int temp;

    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Time Complexity : O(n²)\n");
}