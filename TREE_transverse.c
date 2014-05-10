#include<stdio.h>

typedef struct node
{
        int data;
        struct node *left;
        struct node *right;        
}mynode;

mynode *root;

void add(int value);
void inorder(mynode *root);
void preorder(mynode *root);
void postorder(mynode *root);

int main()
{
    root = (mynode *)0;
    
    add(7);
    add(3);
    add(8);
    add(4);
    add(2);
    add(6);
    add(1);
    add(9);
    
    printf("\n\nIn-order transversal is:  ");
    inorder(root);
    
    printf("\n\nPre-order transversal is:  ");
    preorder(root);
    
    printf("\n\nPost-order transversal is:  ");
    postorder(root);
    
    getch();
    return 0;
}


void add(int value)
{
     mynode *temp, *prev, *curr;
     temp = malloc(sizeof(mynode));
     temp -> data = value;
     temp -> left = (mynode *)0;
     temp -> right = (mynode *)0;
     
     if(root == (mynode *)0)
             root = temp;
     else
     {
             prev = (mynode *)0;
             curr = root;
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
     
     //printf("\n\nInorder transversal:  ");
     if(root != (mynode *)0)
     {
             inorder(root -> left);
             printf("%d ", root -> data); 
             inorder(root -> right);       
     }
}


void preorder(mynode *root)
{
     //printf("\n\nPreorder transversal:  ");
     if(root != (mynode *)0)
     {
             printf("%d ", root -> data);
             preorder(root -> left);
             preorder(root -> right);
             
     }     
}

void postorder(mynode *root)
{
     
     //printf("\n\nPostorder transversal is:  ");
     if(root != (mynode *)0)
     {
             postorder(root -> left);
             postorder(root -> right);        
             printf("%d ", root -> data);
                           
     }
          
}

