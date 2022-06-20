#include <stdio.h>
void ort(int *a, int i)
{
    int k= a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > k) 
    {
        a[j + 1] = a[j];
        --j;
    }
    a[j + 1] = k;
}

void insertion(int *a, int n)

{
    for (int i = 1; i < n; i++)
    {

        ort(a, i);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    insertion(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}
