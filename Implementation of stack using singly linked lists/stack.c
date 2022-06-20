#include <stdio.h>
#include <stdlib.h>
struct node //creating a node
{
    int d;
    struct node *next;
};
typedef struct node node;
node *top = NULL; //defining the top variable as global
void push()       // pushing an int into the stack
{
    int x;
    scanf("%d", &x);                                                  //scaning the element
    struct node *temp = (struct node *)malloc(sizeof(struct node *)); //dynamic memory allocation
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
    printf("%d\n", x);
}
void isempty() //checking the stack is empty or not
{
    if (top == NULL)
    {
        printf("Empty\n");
    }
    else
        printf("Not empty\n");
}
void Top() //printing the top element
{
    printf("%d\n", top->d);
}
void display() // display all element of the stack
{
    if (top == NULL)
        return;
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp = top;
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
            push();
        if (k == 2)
            pop();
        if (k == 3)
            Top();
        if (k == 4)
            display();
    }
    while (top != NULL)//freeing dynamic allocation
    {
        struct node *t = (struct node *)malloc(sizeof(struct node *));
        t = top;
        top = top->next;
        free(t);
    }
}