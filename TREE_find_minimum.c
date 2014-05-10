#include<stdio.h>

typedef struct node 
{
        int data;
        struct node *left;
        struct node *right;       
}mynode;

void add(mynode **root, int value);
void inorder(mynode *root);
void find_minimum(mynode *root);


int main()
{
    mynode *root;
    root = (mynode *)0;
    
    add(&root, 5);
    add(&root, 3);
    add(&root, 6);
    add(&root, 9);
    add(&root, 8);
    add(&root, 11);
    add(&root, 2);
    
    printf("\nInorder transversal of the tree: ");
    inorder(root);
    find_minimum(root);
    
    
    getch();
    return 0;    
}

void add(mynode **root, int value)
{
          mynode *temp, *prev, *curr;
          temp = malloc(sizeof(mynode));
          temp -> data = value;
          temp -> left = (mynode *)0;
          temp -> right = (mynode *)0;
          
          if(*root == (mynode *)0)
                   *root = temp;
          else
          {
                   prev = (mynode *)0;
                   curr = *root;
                   
                   while(curr != (mynode *)0)
                   {
                              prev = curr;
                              curr = (value < curr -> data)? curr -> left : curr -> right;
                                     
                   }
                   
                   if(value < prev -> data)
                            prev -> left = temp;
                   else
                            prev -> right = temp;
          }
     
}


void inorder(mynode *root)
{
     if(root != (mynode *)0)
     {
             inorder(root -> left);
             printf("%d ", root -> data);
             inorder(root -> right);        
     }
}

void find_minimum(mynode *root)
{
     mynode *temp = root;
     
     while(temp -> left != (mynode *)0)
                temp = temp -> left;
                
     printf("\nMinimum value is %d", temp -> data);
     
     
}
