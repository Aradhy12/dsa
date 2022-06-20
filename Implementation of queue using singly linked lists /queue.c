#include <stdio.h>
#include<stdlib.h>
struct node //creating a node
{
    int d;
    struct node *next;
};
typedef struct node node;
node *front = NULL;
node *rear = NULL;
void enqueue() // pushing an array into the stack
{
    int x;
    scanf("%d", &x); //scaning the element
    struct node *temp = (struct node *)malloc(sizeof(struct node *));

    if (temp == NULL)
    {
        printf("Enqueue Failure\n");
    }
    temp->d = x;
    temp->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}
void dequeue() //deleting from the top
{
    int x;
    node *temp; //declaring a temp variable to
    if (front == NULL)
    {
        printf("Dequeue failure");
        return;
    }
    x = front->d;
    temp = front;
    front = front->next; //moving front to the  next position
    if (front ==NULL )
        rear = NULL;
    free(temp); //freeing memory
    printf("%d\n", x);
}
void isempty() //checking the queue is empty or not
{
    if (front == NULL)
    {
        printf("Empty\n");
    }
    else
        printf("Not empty\n");
}
void peek() //printing the top element
{
    printf("%d\n", front->d);
}
void display() // display all element of the stack
{
    struct node *temp;
    temp = front;
    if (temp==NULL)
   { printf("Empty List");}

    while (temp != NULL)
    {
        printf("%d\n", temp->d);
        temp = temp->next;
    }
}
void main()
{
    int k = -1;
    int i = 5;
    while (i == 5)
    {
        scanf("%d", &k);
        if (k == 0)
            isempty();
        if (k == 1)
            enqueue();
        if (k == 2)
            dequeue();
        if (k == 3)
            peek();
        if (k == 4)
            display();
            if(k==5)
            {
                i=0;
            }
    }
    while (front != NULL)
    {
        struct node *t ;
        t = front;
        front= front->next;
        free(t);
    }
}