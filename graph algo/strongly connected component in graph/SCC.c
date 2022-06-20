#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *head = NULL;
int clk = 0;      // clk
node *top = NULL; // defining the top variable as global
void push(int x)  // pushing an int into the stack
{

    scanf("%d", &x);                                                  // scaning the element
    struct node *temp = (struct node *)malloc(sizeof(struct node *)); // dynamic memory allocation
    if (temp == NULL)
        printf("Push Failure\n");
    temp->data = x;
    temp->next = top;
    top = temp;
}
int pop() // deleting from the top of stack
{
    int x;
    node *temp; // declaring a temp variable to
    if (top == NULL)
    {
        printf("Pop failure");
        return -1;
    }
    x = top->data;
    temp = top;
    top = top->next; // moving the tpo to  top next
    free(temp);      // freeing memory
    return x;
}
void makeedge(struct node *s, int i, int j)
{
    struct node *newnode = NULL, *temp = NULL;
    newnode = (struct node *)malloc(sizeof(struct node));
    temp = &s[i];
    newnode->data = j;
    newnode->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
typedef struct node node;

void dfs(int i, struct node *p, int *visited, int v, int *entry, int *exit, int par, int *part)
{
    int r;
    entry[i] = clk;
    clk++;
    struct node *temp = NULL;
    temp = &p[i];
    head = &p[i];

    part[i] = par;

    while (temp->next != NULL)
    {

        r = temp->next->data;

        if (visited[r] == -1)
        {
            visited[r] = 0;
            dfs(r, p, visited, v, entry, exit, i, part);
        }
        temp = temp->next;
    }
    exit[i] = clk;
    clk++;
    push(i);//pushing in order of decreasing order of exit time
}
int w = 0;
void dfs2(int i, struct node *p, int *visited, int v, int *entry, int *exit, int par, int *part)//dfs with print
{
    int r;
    entry[i] = clk;
    clk++;

    if (w != 0)
    {
        printf(" ");
    }
    w = 1;

    struct node *temp = NULL;
    temp = &p[i];
    head = &p[i];
    printf("%d", i + 1);
    part[i] = par;

    while (temp->next != NULL)
    {

        r = temp->next->data;

        if (visited[r] == -1)
        {
            visited[r] = 0;
            dfs2(r, p, visited, v, entry, exit, i, part);
        }
        temp = temp->next;
    }
    exit[i] = clk;
    clk++;
}
int main()
{

    int v, i, j; // v - no of vertices, e-no of edges,
    scanf("%d", &v);
    struct node a[v];
    struct node b[v];
    int visited[v];
    int entry[v];
    int exit[v];
    int part[v];
    for (int k = 0; k < v; k++)
    {
        visited[k] = -1;
        a[k].next = NULL;
        b[k].next = NULL; // making the next of each node=NULL
        entry[k] = -1;
        exit[k] = -1;
    }
    for (int k = 0; k < v;)
    {
        scanf("%d", &i);
        if (i != -1)
        {
            makeedge(a, k, i - 1);
            makeedge(b, i - 1, k);//g reverse
        }
        else
            k++;
        
    }
    scanf("%d", &i);
    for (int t = 0; t < v; t++)//printing reverse graph
    {
        head = &b[t];
        if (head->next == NULL)
            printf("-1\n");
        else
        {
            while (head->next != NULL)
            {
                head = head->next;
                int u = head->data;
                printf("%d ", u + 1);
            }
            printf("-1\n");
        }
    }
    visited[i - 1] = 0;
    dfs(i - 1, a, visited, v, entry, exit, -1, part);

    for (int r = 0; r < v; r++)
    {
        if (visited[r] == -1)
        {
            visited[r] = 0;
            dfs(r, a, visited, v, entry, exit, -1, part);
        }
    }
    int e;
    for (int r = 0; r < v; r++)
    {
        visited[r] = -1;
    }
    while (top != NULL)
    {
        e = pop();//poping the first elemet and 1 dfs will give us 1 connected components
        if (visited[e] == -1)
        {
            visited[e] = 0;
            w = 0; // to set with output
            dfs2(e, b, visited, v, entry, exit, -1, part);
            printf("\n");
        }
    }
}