// calculating shortestest route for weighted graph 

#include <stdio.h>

#define V 4

int main()
{
    int graph[V][V] =
    {
        {0,4,2,0},
        {4,0,1,5},
        {2,1,0,3},
        {0,5,3,0}
    };

    printf("Weighted Adjacency Matrix\n\n");

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            printf("%2d ",graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}