#include <stdio.h>
struct node
{
    int x;
    struct node *next;
};
int main()
{
    struct node a1, a2, a3, a4, a5, o; //declaring node
    struct node *head = NULL;          //declaring pointer
    struct node *p = NULL;
    struct node *w = NULL;

        head = &a1; //link the link list
    p = head;// 1st pointer
    w = &a2; //2nd pointer

    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    a5.next = 0;
    while (p != NULL) //inserting values
    {
        scanf("%d", &(*p).x);
        p = p->next;
    }
int r=1;
    p = head;// p is at head at w 1 step ahead (intiAL condition)
    int temp;
    printf("%d\n",(*p).x);
     while (w != NULL)// terminating when second pionter is null
    {
        p = head;
        while (p != w)
        {
            if ((*p).x > (*w).x)// swaping the element until the lsit till w is sorted
            {
                temp = (*p).x;
                (*p).x = (*w).x;
                (*w).x = temp;
            }
            else
                p = p->next;
        }p=head;
    
        
        w=w->next;
        while(p!=w)
        {printf("%d\n",(*p).x);
        p=p->next;
        }
        
    }
    
    return 0;
}

