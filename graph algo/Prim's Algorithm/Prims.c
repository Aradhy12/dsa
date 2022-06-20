#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int weight;
    struct node *next;
};
typedef struct node node;
typedef struct minheapnode
{
    int s;
    int vertex;
    int from;

} minheap;
void swap(minheap *x, minheap *y) // swapping element of the minheap
{
    minheap temp;

    temp = *x;
    *x = *y;
    *y = temp;
    return;
}
void minheapify(minheap *H, int i, int n)
{
    int smallest = i; // let smallest is equal to the position at which we are calling minheapify
    if (i >= (n) / 2) // leaf node
    {
        return;
    }

    if (H[2 * i + 1].s < H[i].s)
    {

        smallest = 2 * i + 1;
    }

    if ((2 * i + 2) <= (n - 1) && H[2 * i + 2].s < H[smallest].s)
    {
        smallest = 2 * i + 2;
    }

    if (H[smallest].s == H[i].s)
    {

        return;
    }
    if (smallest != i)
    {
        swap(&H[i], &H[smallest]);
        minheapify(H, smallest, n);
    }
}

void shiftup(minheap *H, int i)
{
    while (i > 0 && H[i].s <= H[(i - 1) / 2].s)
    {
        swap(&H[i], &H[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    return;
}

void insert(minheap *H, minheap x, int *n)
{
    (*n)++;               // increasing the size of arry
    H[(*n) - 1] = x;      // store the new element in the last position of the tree
    shiftup(H, (*n) - 1); // and shift up it recurssively
}
minheap extractmin(minheap *H, int *n) // this function deletes the min value in the heap
{
    minheap temp;
    temp = H[0];          // store the minvalue in the temp
    H[0] = H[(*n) - 1];   // copy the last value in heap to root position
    (*n)--;               // decraese the size of the array
    minheapify(H, 0, *n); // call minheapify
    return temp;
}
// this function deletes the element of the heap at a particular position
void makeheap(minheap *H, int n)
{

    int ri = (n - 1) / 2; // last non leafnode
    for (int i = ri; i >= 0; i--)
    {

        minheapify(H, i, n);
    }
}

void makeedge(struct node *s, int i, int j, int w)
{
    struct node *newnode = NULL, *temp = NULL;
    newnode = (struct node *)malloc(sizeof(struct node));
    temp = &s[i];
    newnode->data = j;
    newnode->weight = w;
    newnode->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void prism(struct node *a, int s, int *weight, int v)
{
    int visited[v];
  
    s = s - 1;
    int n = 1;//number of element in minheap
    int child[v];
    int tc[v];//for printing 
    int w[v];//for printing weight
    minheap t[v]; // creating minheap of size v with weight as it prority
    for (int i = 0; i < v; i++)
    {
        t[i].s = 99999;
        t[i].vertex = -1;
        t[i].from = -1;
        visited[i] = 0;
        child[i] = -1;
        w[i] = 10000;
        tc[i] = -1;
    }
    int ie = 0;//printing 
    t[0].s = 0;

    t[0].vertex = s;
    t[0].from = -1;
    makeheap(t, n);//creating the minheap of size n
    minheap temp;

    while (n != 0)
    {
        temp = extractmin(t, &n);
      
        if (temp.from!=-1&&tc[temp.vertex]==-1)//if we haven't print the vertice
        {
            tc[temp.vertex] = 0;
            child[temp.from] = temp.vertex;
            w[temp.from] = temp.s;
            if (ie < v )
            {
                printf("%d %d %d\n", temp.from + 1, temp.vertex + 1, temp.s);ie++;
            }
        }
        // taking the minimum element of the minheap
        if (visited[temp.vertex] == 0)
        {
            visited[temp.vertex] = 1;
            struct node *tem = NULL;
            tem = &a[temp.vertex];
            while (tem->next != NULL)
            {
                minheap x;
                x.vertex = tem->next->data;
                x.s = tem->next->weight;
                x.from = temp.vertex;
                if (visited[tem->next->data] == 0)//if that vertex has notbeen visisted than inserting the minheap
                {
                    insert(t, x, &n);
                }
                tem = tem->next;
            }
        }
    }
  
    
  
}
int main()
{

    int v, i, j; // v - no of vertices, e-no of edges,
    scanf("%d", &v);
    struct node a[v];
    int visited[v];
    int weight[v];
    int pred[v];

    for (int k = 0; k < v; k++)
    {
        visited[k] = -1;
        a[k].next = NULL;
        weight[k] = 99999;
        // making the next of each node=NULL
    }
    int w;
    for (int k = 0; k < v;)
    {
        scanf("%d", &i);

        if (i != -1)
        {
            scanf("%d", &w);
            makeedge(a, k, i - 1, w); // directed graph
        }
        else
            k++;
    }
    int s;
    scanf("%d", &s);
    prism(a, s, weight, v);
}
