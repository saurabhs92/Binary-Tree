#include<stdio.h>

typedef struct node 
{
        int data;
        struct node *left;
        struct node *right;       
}mynode;

#define true 1
#define false 0

void add(mynode **root, int value);
void inorder(mynode *root);
int identical(mynode *a, mynode *b);


int main()
{
    mynode *root1, *root2;
    root1 = (mynode *)0;
    root2 = (mynode *)0;
    int flag;
    
    add(&root1, 5);
    add(&root1, 2);
    add(&root1, 6);
    add(&root1, 9);
    
    
    add(&root2, 5);
    add(&root2, 3);
    add(&root2, 6);
    add(&root2, 9);
    
    printf("\n\nFirst tree is: ");
    inorder(root1);
    
    printf("\n\nSecond tree is: ");
    inorder(root2);
    
    flag = identical(root1, root2);
    if(flag)
            printf("\n\nIdentical trees! ");
    else
            printf("\n\nNot identical :/ ");
            
    
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

int identical(mynode *a, mynode *b)
{
     if(a == (mynode *)0 && b == (mynode *)0)
             return(true);
     else if(a -> data == b -> data && identical(a -> left, b -> left) && identical(a -> right, b -> right))
             return(true);
     else
             return(false);
              
     
     
}
