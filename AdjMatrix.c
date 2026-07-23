//while working with graph lets understand how to use adjacency matrix and adjacency list to represent a graph. In this code we are using adjacency list representation of graph.
//lets take 4*4 matrix with sample data

#include<stdio.h>

int main()
{
    int n = 4;

    int graph[4][4] =
    {
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,0},
        {0,1,0,0}
    };

    printf("Adjacency Matrix\n\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
