/*
=========================================
LINEAR DATA STRUCTURE - ARRAY OPERATIONS
=========================================

Operations

1. Display Array
2. Insert Element
3. Delete Element
4. Update Element
5. Search Element
6. Sort Array
7. Exit

=========================================
*/

#include<stdio.h>

#define MAX 100

// Function Prototypes
void display(int arr[], int size);
void insert(int arr[], int *size);
void deleteElement(int arr[], int *size);
void update(int arr[], int size);
void search(int arr[], int size);
void sort(int arr[], int size);

int main()
{
    int arr[MAX];
    int size;
    int choice;

    // Step 1 : Create Array
    printf("Enter Number of Elements : ");
    scanf("%d",&size);

    printf("Enter Array Elements\n");

    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);

    do
    {
        printf("\n==============================\n");
        printf(" ARRAY OPERATIONS MENU\n");
        printf("==============================\n");

        printf("1. Display\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Update\n");
        printf("5. Search\n");
        printf("6. Sort\n");
        printf("7. Exit\n");

        printf("Enter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                display(arr,size);
                break;

            case 2:
                insert(arr,&size);
                break;

            case 3:
                deleteElement(arr,&size);
                break;

            case 4:
                update(arr,size);
                break;

            case 5:
                search(arr,size);
                break;

            case 6:
                sort(arr,size);
                printf("Array Sorted Successfully\n");
                break;

            case 7:
                printf("Program Ended\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    }while(choice!=7);

    return 0;
}

//-----------------------------------------
// Display Array
//-----------------------------------------
void display(int arr[], int size)
{
    printf("\nArray Elements\n");

    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);

    printf("\n");

    printf("Time Complexity : O(n)\n");
}

//-----------------------------------------
// Insert Element
//-----------------------------------------
void insert(int arr[], int *size)
{
    int pos,value;

    printf("Enter Position : ");
    scanf("%d",&pos);

    printf("Enter Value : ");
    scanf("%d",&value);

    // Shift elements right
    for(int i=*size;i>pos;i--)
        arr[i]=arr[i-1];

    arr[pos]=value;

    (*size)++;

    printf("Element Inserted\n");

    printf("Time Complexity : O(n)\n");
}

//-----------------------------------------
// Delete Element
//-----------------------------------------
void deleteElement(int arr[], int *size)
{
    int pos;

    printf("Enter Position : ");
    scanf("%d",&pos);

    // Shift elements left
    for(int i=pos;i<*size-1;i++)
        arr[i]=arr[i+1];

    (*size)--;

    printf("Element Deleted\n");

    printf("Time Complexity : O(n)\n");
}

//-----------------------------------------
// Update Element
//-----------------------------------------
void update(int arr[], int size)
{
    int pos,value;

    printf("Enter Position : ");
    scanf("%d",&pos);

    printf("Enter New Value : ");
    scanf("%d",&value);

    arr[pos]=value;

    printf("Updated Successfully\n");

    printf("Time Complexity : O(1)\n");
}

//-----------------------------------------
// Search Element
//-----------------------------------------
void search(int arr[], int size)
{
    int key;

    printf("Enter Number to Search : ");
    scanf("%d",&key);

    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            printf("Element Found at Position %d\n",i);
            printf("Time Complexity : O(n)\n");
            return;
        }
    }

    printf("Element Not Found\n");

    printf("Time Complexity : O(n)\n");
}

//-----------------------------------------
// Bubble Sort
//-----------------------------------------
void sort(int arr[], int size)
{
    int temp;

    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("Time Complexity : O(n²)\n");
}
