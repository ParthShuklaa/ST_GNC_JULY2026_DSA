#include <stdio.h>

int main()
{
    int accounts[3][2] =
    {
        {1,5},
        {7,3},
        {3,5}
    };

    int rows = 3; // they are 3 customers
    int cols = 2; // they aRE 2 accounts for each customer

    int maxWealth = 0;
    int i, j;

    for(i = 0; i < rows; i++)
    {
        int currentWealth = 0;

        for(j = 0; j < cols; j++)
        {
            currentWealth = currentWealth + accounts[i][j];
        }

        if(currentWealth > maxWealth)
        {
            maxWealth = currentWealth;
        }
    }

    printf("Richest Customer Wealth = %d", maxWealth);

    return 0;
}