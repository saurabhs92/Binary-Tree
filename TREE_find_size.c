#include<stdio.h>

typedef struct node 
{
        int data;
        struct node *left;
        struct node *right;       
}mynode;

void add(mynode **root, int value);
void inorder(mynode *root);
int find_size(mynode *root);


int main()
{
    mynode *root;
    root = (mynode *)0;
    int size;
    add(&root, 5);
    add(&root, 21);
    add(&root, 6);
    add(&root, 9);
    add(&root, 10);
    add(&root, 1);
    add(&root, 30);
    add(&root, 19);
    add(&root, 8);
    
    inorder(root);
    size = find_size(root);
    printf("\n\nSize is: %d ", size);
    
    
    
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

int find_size(mynode *root)
{
     if(root == (mynode *)0)
             return(0);
     else
             return(find_size(root -> left) + find_size(root -> right) + 1);    
     
}
