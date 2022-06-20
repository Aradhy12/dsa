#include <stdio.h>
#include <stdlib.h>
struct node //defining the structure for a doulble linklist
{
    int d;
    struct node *prev;
    struct node *next;
};
typedef struct node node;
node *head = NULL;
//defing head pointer globlaly to store the head address of the link list
void insert()
{
    int x;
    scanf("%d", &x);                                                  //scaning the element
    struct node *temp = (struct node *)malloc(sizeof(struct node *)); //dynamic memory allocation
    temp->d = x;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;

        return;
    }
    head->next = temp;
    temp->prev = head;
    head = temp;
}
void print()
{
    node *temp;
    temp = head;
    while (temp->prev != NULL)
    {
        temp = temp->prev;
    }
    while (temp != NULL)
    {
        printf("%d\n", temp->d);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->d);
        temp = temp->prev;
    }
}
void delf()
{
    node *cur = head;
    node *curn;
    while (cur->prev != NULL)
    {
        curn = cur;
        cur = cur->prev;
    }
    cur->next = NULL;
    curn->prev = NULL;
    free(cur);
}

void delb()
{
    node *temp;
    temp = head;
    head = head->prev;
    temp->prev = NULL;
    head->next = NULL;
    free(temp);
}
void main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        insert();
    }
    print();
    delf();
    delb();
    print();
    node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}