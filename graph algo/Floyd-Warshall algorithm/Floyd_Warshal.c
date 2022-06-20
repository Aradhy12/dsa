#include <stdio.h>
#include <stdlib.h>//program to compute shortest distance between all point 
int main()
{
    int n;
    scanf("%d", &n);//taking  the number of vertices
    int a[n + 1][n + 1];
    int pred[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 55555)
            {
                pred[i][j] = i;
            }
            else
                pred[i][j] = -1;
        }
    }
    for (int k = 1; k <= n; k++)
    {//picking all the vertices as the source vertices
        for (int i = 1; i <= n; i++)
        {
  //picking all the vertices as destination for the source vertices
            for (int j = 1; j <= n; j++)
            {
                //if the shortest path exits through A vertices than changing the weight
                if (a[i][k] + a[k][j] < a[i][j] && a[i][k] != 55555 && a[k][j] != 55555)
                {
                    a[i][j] = a[i][k] + a[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
        if (k == 2)
        {
            printf("Pairwise Distance Matrix After Two Rounds\n");
            for (int y = 1; y <= n; y++)
            {
                for (int j = 1; j <= n; j++)
                {
                    printf("%d", a[y][j]);
                    if(j==n)
                    {
                    continue;
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            printf("Pairwise Predecessor Matrix After Two Rounds\n");//output
            for (int y = 1; y <= n; y++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (pred[y][j] != -1 && y != j)
                    {
                        printf("%d", pred[y][j]);
                    }
                    else
                    {
                        printf("NIL");
                    }
                    if(j==n)
                    {
                    continue;
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
    }
    printf("Final Pairwise Distance Matrix\n");
    for (int y = 1; y <= n; y++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d", a[y][j]);
            if(j==n)
                    {
                    continue;
                    }
                    else
                    {
                        printf(" ");
                    }
        }
        printf("\n");
    }
    printf("Final Pairwise Predecessor Matrix\n");
    for (int y = 1; y <= n; y++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (pred[y][j] != -1 && y != j)
            {
                printf("%d", pred[y][j]);
            }
            else
            {
                printf("NIL");
            }
            if(j==n)
                    {
                    continue;
                    }
                    else
                    {
                        printf(" ");
                    }
        }
         printf("\n");
    }
}