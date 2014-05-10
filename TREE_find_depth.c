#include<stdio.h>

typedef struct node 
{
        int data;
        struct node *left;
        struct node *right;       
}mynode;

void add(mynode **root, int value);
void inorder(mynode *root);
int find_maximum_depth(mynode *root);


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
    
    printf("\nInorder Transversal of tree: ");
    inorder(root);
    depth = find_maximum_depth(root);
    printf("\n\nDepth is: %d ", depth);
    
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

int find_maximum_depth(mynode *root)
{
    
     if(root == (mynode *)0)        // must be at the beginning or won't work!
         return(0);
     else
     {
              
         int height1 = find_maximum_depth(root -> left); // must be inside else 
         int height2 = find_maximum_depth(root -> right);
         
         
         if(height1 < height2)               
                    return(height2 + 1);
         else
                    return(height1 + 1);           
             
     }
     
}
