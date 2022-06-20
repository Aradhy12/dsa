#include <stdio.h>//program to implement union ds
#include <stdlib.h>
void makeset(int *par, int n, int *h)//making n set
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        h[i] = 0;
    }
}
int find(int *par, int n, int x)//this retrun the root of the set
{

    while (par[x] != x)
    {
        x = par[x];
    }
    return x;
}
void unions(int *par, int n, int *h)//join to set if they are not in the same set
{
    int x;
    int y;
    scanf("%d %d", &x, &y);
    int i = find(par, n, x);
    int j = find(par, n, y);
    if (i == j)
        return;
    else if (h[i] == h[j])
    {
        par[j] = i;
        h[i] += 1;
    }
    else if (h[i] < h[j])
    {
        par[i] = j;
    }
    else
        par[j] = i;
    i = find(par, n, i);

    printf("%d %d\n", i, h[i]);
}
void print(int *par, int n)//printing the set
{
    int x;
    for (int i = 1; i <= n; i++)
    {
        x = find(par, n, i);
        printf("%d %d\n", i, x);
    }
}

int main()
{
    int n;
    scanf("%d", &n);//taking input number of element
    int par[n + 1];//creating array for par
    int h[n+1];//taking input for height
    makeset(par, n, h);
    int i;
    int x;
    while (1)
    {
        scanf("%d", &i);
        if (i == 1)
        {
            scanf("%d", &x);
            int t = find(par, n, x);
            printf("%d\n", t);
        }
      else  if (i == 2)
        {unions(par,n,h);
        }
       else if (i == 3)
        {
            print(par, n);
        }
        else
            break;
    }
}