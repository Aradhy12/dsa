#include <stdio.h>
#include <stdlib.h>
struct nodes//creating a node
{
    int d;
    struct nodes *next;
};
typedef struct nodes node;
node *top = NULL; //defining the top variable as global
void push(int x)       // pushing an int into the stack
{
     
     
                                                //scaning the element
    struct nodes *temp = (struct nodes *)malloc(sizeof(struct nodes *)); //dynamic memory allocation
    if (temp == NULL)
        printf("Push Failure\n");
    temp->d = x;
    temp->next = top;
    top = temp;
}
void pop() //deleting from the top
{
    
    
    
    int x;
    node *temp; //declaring a temp variable to
    if (top == NULL)
    {
        printf("Pop failure");
           return;
    }
    x = top->d;
    temp = top;
    top = top->next; //moving the tpo to  top next
    free(temp);      //freeing memory
    printf("%d ", x+1);
}
void isemptys() //checking the stack is empty or not
{
    if (top == NULL)
    {
        printf("Empty\n");
    }
    else
        printf("Not empty\n");
}
int searchs(int k) // display all element of the stack
{
    
    
    if (top == NULL)
        return -1;
    struct nodes *temp = (struct nodes *)malloc(sizeof(struct nodes*));
    temp = top;
    while (temp != NULL)
    {if(temp->d==k)
      return 1;
        temp = temp->next;
    }
    return 0;
}

struct node
{
    int data;

    int weight;
    struct node *next;
};
int m = 0;int y=-1;
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
void bellford(struct node *a, int s, int *weight, int *pred, int v, int e)
{
    int w;
    int u;
    struct node *temp = NULL;
    
    
    for (int i = 1; i < v; i++)
    {

        for (int j = 0; j < v; j++)
        {
            temp = &a[j];
            while (temp->next != NULL)
            {
                w = temp->next->weight;
                u = temp->next->data;
                if (weight[u] > weight[j] + w)
                {
                    weight[u] = weight[j] + w;
                    pred[u] = j;
                }
                temp = temp->next;
            }
        }
    }



    for (int j = 0; j < v; j++)
    {
        temp = &a[j];
        while (temp->next != NULL)
        {
            w = temp->next->weight;
            u = temp->next->data;
            if (weight[u] > weight[j] + w)
            {
                m = -1;
                pred[u] = j;
                y=u;
                return;
            }
            
            temp = temp->next;
        }

    }
    
    
    

    if (m != -1)// if no negative edge cycle are there
    {
        for (int i = 0; i < v; i++)
        {
            if (weight[i] == 9999)
                printf("Unreachable\n");
            else if (pred[i] != -1)
                printf("%d %d\n", weight[i], pred[i] + 1);
            else
                printf("%d %d\n", weight[i], pred[i]);
        }
    }
    
    
    
}

int main()
{

    int v, e, i, j; // v - no of vertices, e-no of edges,
    scanf("%d", &v);
    scanf("%d", &e);
    int pred[v];
    struct node a[v];
    int visited[v];
    int weight[v];
    for (int k = 0; k < v; k++)
    {
        visited[k] = -1;
        a[k].next = NULL;
        pred[k] = -1;
        weight[k] = 9999;
        // making the next of each node=NULL
    }
    int w;
    
    
    
    for (int k = 0; k < e; k++)
    {
       
       
        scanf("%d", &i);
        scanf("%d", &j);
        scanf("%d", &w);
        makeedge(a, i - 1, j - 1, w);//making an edge
    }
    
    int s;
    scanf("%d", &s);
    weight[s - 1] = 0;
    bellford(a, s, weight, pred, v, e);
    int last;
     if (m == -1)
    {last=y;
        while (visited[last]!= 1)//startung from last change vertex and checking for cycle from that edge
        {

           push(last);
           visited[last]=1;
           last=pred[last];
        }

        while (top->d != last)//now retraecing the element using the stack
        {
            pop();
        }
        printf("%d", last + 1);
    }
    
}