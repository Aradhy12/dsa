#include <stdio.h>//program to check a graph is a dag
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *head = NULL;
int clk = 0;
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
int pop() // deleting from the top
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
    printf("%d\n", x + 1);
}
void isemptys() // checking the stack is empty or not
{
    if (top == NULL)
    {
        printf("Empty\n");
    }
    else
        printf("Not empty\n");
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
    push(i);// if  a dag ,will give topological sort
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
            makeedge(a, k, i - 1); // directed graph
        }
        else
            k++;
       
    }
    scanf("%d", &i);
    int m = 1;
    visited[i - 1] = 0;
    dfs(i - 1, a, visited, v, entry, exit, -1, part);//starting dfs from i vertex

    for (int r = 0; r < v; r++)
    {
        if (visited[r] == -1)
        {
            visited[r] = 0;
            dfs(r, a, visited, v, entry, exit, -1, part);
        }
    }
    for (int i = 0; i < v; i++)
    {
        if (part[i] != -1)
            printf("%d %d %d\n", entry[i], exit[i], part[i] + 1);
        else
            printf("%d %d %d\n", entry[i], exit[i], part[i]);
    }

    struct node *temp = NULL;
    for (int t = 0; t < v; t++)
    {
        temp = &a[t];
        while (temp->next != NULL)
        {
            int r = temp->next->data;
            if (entry[r] < entry[t] && exit[t] < exit[r])// backedge condition
            {
                if (m != -1)
                {
                    printf("Not a DAG\n");
                    m = -1;
                }
                printf("%d %d %d %d\n", entry[r], entry[t], exit[t], exit[r]);
            }
            temp = temp->next;
        }
    }
    if (m != -1) // no backedge
    {
        printf("DAG\n");
        while (top != NULL)//poping element will give topological sort
        {
            pop();
        }
    }
}
