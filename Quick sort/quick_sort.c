#include <stdio.h>

void swap(int *l, int *m)
{
    int temp = *l;
    *l = *m;
    *m = temp;
}
int part(int *a, int beg, int end,int index)
{
    int p = beg - 1;
    for (int i =beg ; i <= end; i++)
    {
        if (a[i] < index)
        {
            p++;
            swap(&a[p], &a[i]);
        }
    }
    swap(&a[p + 1], &a[end]);
    return (p + 1);
}

void sort(int *a, int l, int r)
{
    if (l < r)
    {
        int pi = part(a, l, r,a[r]);//after this pi will in it correct position and left side have smaller element 
        sort(a, l, pi - 1);//function calling for left half
        sort(a, pi + 1, r);//for right half
    }
}

void main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}