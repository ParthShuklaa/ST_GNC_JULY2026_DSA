//Steps for perfoming Array Rotation based on user input 
//Step 1: Read array size
//Step 2: Input array elements
//Step 3: Read number of positions to rotate
//Step 4: Rotate the array by K positions

//ArrayRotation is a process of shifting the elements of an array to the left or right by a certain number of positions. In this case, we will rotate the array to the right by K positions. 

/*
===========================================================
Program : Array Rotation (Right Rotation)

Steps:
Step 1: Read array size
Step 2: Input array elements
Step 3: Read number of positions (K) to rotate
Step 4: Rotate the array to the right by K positions
Step 5: Display the rotated array

Example:
Input  : 10 20 30 40 50
K = 2

Output : 40 50 10 20 30
===========================================================
*/

#include <stdio.h>

int main()
{
    int arr[100];
    int size;
    int k;
    int temp;

    // Step 1: Read array size
    printf("Enter Array Size: ");
    scanf("%d", &size);

    // Step 2: Input array elements
    printf("\nEnter %d Elements:\n", size);

    for(int i = 0; i < size; i++)
    {
        printf("Element [%d] : ", i);
        scanf("%d", &arr[i]);
    }

    // Step 3: Read number of rotations
    printf("\nEnter Number of Positions to Rotate: ");
    scanf("%d", &k);

    // Handle rotation greater than array size
    k = k % size;

    // Step 4: Rotate array one position at a time
    for(int r = 1; r <= k; r++)
    {
        // Save last element
        temp = arr[size - 1];

        // Shift all elements to the right
        for(int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }

        // Place last element at first position
        arr[0] = temp;
    }

    // Step 5: Display rotated array
    printf("\nArray After Right Rotation:\n");

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}