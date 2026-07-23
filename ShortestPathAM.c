//shortest path 

#include<stdio.h>

#define V 4

int main()
{
    int graph[V][V]=
    {
        {0,4,2,0},
        {4,0,1,5},
        {2,1,0,3},
        {0,5,3,0}
    };

    int path[20];
    int vertices;
    int total=0;

    printf("Weighted Adjacency Matrix\n\n");

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
            printf("%2d ",graph[i][j]);

        printf("\n");
    }

    printf("\nHow many vertices are in your path? ");
    scanf("%d",&vertices);

    printf("Enter the path:\n");

    for(int i=0;i<vertices;i++)
        scanf("%d",&path[i]);

    printf("\n");

    for(int i=0;i<vertices-1;i++)
    {
        int from=path[i];
        int to=path[i+1];

        if(graph[from][to]==0)
        {
            printf("No Road Exists Between %d and %d\n",from,to);
            return 0;
        }

        printf("%d -> %d = %d\n",from,to,graph[from][to]);

        total += graph[from][to];
    }

    printf("\nTotal Distance = %d\n",total);

    return 0;
}