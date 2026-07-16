/*
==========================================================
        DYNAMIC ARRAY - PART 2
        Insert | Delete | Update
==========================================================

Objective
---------
Perform basic operations on a Dynamic Array.

Operations
----------
1. Display Array
2. Insert Element
3. Delete Element
4. Update Element
5. Exit

Topics Covered
--------------
✓ Dynamic Array
✓ malloc()
✓ Functions
✓ Arrays
✓ Loops
✓ Time Complexity

==========================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

//-----------------------------------------------------
// Function Prototypes
//-----------------------------------------------------
void display(int arr[], int size);
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
void updateElement(int arr[], int size);

//-----------------------------------------------------
// Main Function
//-----------------------------------------------------
int main()
{
    int *arr;
    int size;
    int choice;

    printf("=========================================\n");
    printf(" DYNAMIC ARRAY - INSERT DELETE UPDATE\n");
    printf("=========================================\n");

    printf("Enter Initial Array Size : ");
    scanf("%d", &size);

    if(size <= 0 || size > MAX_SIZE)
    {
        printf("Invalid Size!\n");
        return 0;
    }

    // Allocate memory
    arr = (int *)malloc(MAX_SIZE * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return 0;
    }

    printf("\nEnter %d Elements\n", size);

    for(int i = 0; i < size; i++)
    {
        printf("Element [%d] : ", i);
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n=========================================\n");
        printf("           MENU\n");
        printf("=========================================\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Update Element\n");
        printf("5. Exit\n");

        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                display(arr, size);
                break;

            case 2:
                insertElement(arr, &size);
                break;

            case 3:
                deleteElement(arr, &size);
                break;

            case 4:
                updateElement(arr, size);
                break;

            case 5:
                printf("\nReleasing Memory...\n");
                free(arr);
                printf("Memory Released Successfully.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}

//-----------------------------------------------------
// Display Array
//-----------------------------------------------------
void display(int arr[], int size)
{
    printf("\nArray Elements\n");

    if(size == 0)
    {
        printf("Array is Empty.\n");
        return;
    }

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    printf("Time Complexity : O(n)\n");
}

//-----------------------------------------------------
// Insert Element
//-----------------------------------------------------
void insertElement(int arr[], int *size)
{
    int position;
    int value;

    if(*size >= MAX_SIZE)
    {
        printf("Array is Full.\n");
        return;
    }

    printf("Enter Position (0-%d) : ", *size);
    scanf("%d", &position);

    if(position < 0 || position > *size)
    {
        printf("Invalid Position.\n");
        return;
    }

    printf("Enter Value : ");
    scanf("%d", &value);

    // Shift elements to the right
    for(int i = *size; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;

    (*size)++;

    printf("Element Inserted Successfully.\n");
    printf("Time Complexity : O(n)\n");
}

//-----------------------------------------------------
// Delete Element
//-----------------------------------------------------
void deleteElement(int arr[], int *size)
{
    int position;

    if(*size == 0)
    {
        printf("Array is Empty.\n");
        return;
    }

    printf("Enter Position to Delete (0-%d) : ", *size - 1);
    scanf("%d", &position);

    if(position < 0 || position >= *size)
    {
        printf("Invalid Position.\n");
        return;
    }

    // Shift elements left
    for(int i = position; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*size)--;

    printf("Element Deleted Successfully.\n");
    printf("Time Complexity : O(n)\n");
}

//-----------------------------------------------------
// Update Element
//-----------------------------------------------------
void updateElement(int arr[], int size)
{
    int position;
    int value;

    if(size == 0)
    {
        printf("Array is Empty.\n");
        return;
    }

    printf("Enter Position to Update (0-%d) : ", size - 1);
    scanf("%d", &position);

    if(position < 0 || position >= size)
    {
        printf("Invalid Position.\n");
        return;
    }

    printf("Current Value : %d\n", arr[position]);

    printf("Enter New Value : ");
    scanf("%d", &value);

    arr[position] = value;

    printf("Element Updated Successfully.\n");
    printf("Time Complexity : O(1)\n");
}