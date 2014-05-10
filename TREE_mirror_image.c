#include<stdio.h>

typedef struct node 
{
        int data;
        struct node *left;
        struct node *right;       
}mynode;

void add(mynode **root, int value);
void inorder(mynode *root);
void create_mirror(mynode *root);


int main()
{
    mynode *root;
    root = (mynode *)0;
    int depth; 
    add(&root, 5);
    add(&root, 4);
    add(&root, 6);
    add(&root, 9);
    add(&root, 14);
    add(&root, 3);
    add(&root, 1);
    add(&root, 2);
    
    printf("\n\nIn-order transversal is: ");
    inorder(root);
    create_mirror(root);
    
    printf("\n\nIn-order transversal after mirroring is: ");
    inorder(root);
    
    
    getch();
    return 0;    
}

void add(mynode **root, int value)
{
          tree *temp, *prev, *curr;
          temp = malloc(sizeof(tree));
          temp -> data = value;
          temp -> left = (tree *)0;
          temp -> right = (tree *)0;
          
          if(*root == (tree *)0)
                   *root = temp;
          else
          {
                   prev = (tree *)0;
                   curr = *root;
                   
                   while(curr != (tree *)0)
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

void create_mirror(mynode *root)
{
    mynode *temp;
    if(root == (mynode *)0)
            return;
    else
    {
            create_mirror(root -> left);
            create_mirror(root -> right);
            
            //Swap the pointers in this node
            temp = root -> left;
            root -> left = root -> right;
            root -> right = temp;            
    }
 
 
}
