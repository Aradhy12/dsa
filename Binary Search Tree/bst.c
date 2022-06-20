#include <stdio.h>//program to create bst in c 
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int x; 
    struct node *left;
    struct node *right;
};
typedef struct node Node;
struct node* search2(Node *root, int key)
{
    
    if (root == NULL || root->x == key)
       return root;
    
    // Key is greater than root's key
    if (root->x < key)
       return search2(root->right, key);
 
    else
    return search2(root->left, key);
}
struct node *make(int x){
    struct node *bst = (struct node*)malloc(sizeof(struct node *)); //creating memory in heap
    bst->x= x;
    bst->left = bst->right = NULL;
    return bst;
}
struct node* insert(struct node *root, int x)//inserting in bst
{
    if (root == NULL)
    {
        root = make(x);
    }

    else if (x<= root->x)
        {
            root->left =insert(root->left, x);
        }

    else
    {
        root->right = insert(root->right, x);
    }
    return root;
}
bool search(struct node *root, int data)//searching in the bst
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->x == data)
    {
        return true;
    }
    else if (data <= root->x)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}
void Inorder(struct node *node)

{
    if (node == NULL)
        return;

    Inorder(node->left);

    printf("%d\n", node->x);

    Inorder(node->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
        return;

    // first recur on left subtree
    postorder(root->left);

    // then recur on right subtree
    postorder(root->right);

    // now deal with the node
    printf("%d\n", root->x);
}
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d\n", root->x);
    preorder(root->left);
    preorder(root->right);
}
void predecessor(struct node *root, int data)
{Node *s;
s=root; //pointer for stroring the root value in every iteration
root=search2(root,data);
   
   int k=-10000;
     if (root == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    else
    {if(root->left!=NULL)
    {
        s=root->left;
        while(s->right!=NULL)
        {
            s=s->right;

        }
        printf("%d\n",s->x);
        return;
    }
        else if(root->left==NULL)
        {
            while(root->x!=s->x)
            {
                if(root->x>s->x)
                {
                    k=s->x;
                    s=s->right;
                }
                else 
                s=s->left;
            }
                if(k==-10000)
                printf("No predecessor\n");
                else
                printf("%d\n",k);
            
        }
    }
}
void successor(struct node *root, int data)
{Node *s;
s=root;
root=search2(root,data);
    //pointer for stroring the root value in every iteration
   int k=-10000;
    if (root == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    else 
    {
        if(root->right!=NULL)
    {
        s=root->right;
        while(s->left!=NULL)
        {
            s=s->left;
        }
        printf("%d\n",s->x);
        return;
    }
    else
    { while(root->x!=s->x)
            {
                if(root->x<s->x)
                {
                    k=s->x;
                    s=s->left;
                }
                else 
                s=s->right;
            }
                if(k==-10000)
                printf("No successor\n");
                else
                printf("%d\n",k);
            
    
         }
    }
    
}
int main()
{
    struct node *root = NULL;
    

    while (1)
    {
        int choice = 0, x = 0;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &x);
            root = insert(root, x);
            break;
        case 2:
            scanf("%d", &x);
            if (search(root, x) == true)
                printf("Found\n");
            else
                printf("Not Found\n");
            break;
        case 3:
            Inorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            scanf("%d", &x);
            predecessor(root, x);
            break;
        case 7:
            scanf("%d", &x);
            successor(root, x);
            break;
        case 8:
            return 0;
        }
    }
    return 0;
}

