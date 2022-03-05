#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node
{
   // int data;
    char data[20];
    struct node *left;
    struct node * right;

}*root=NULL;

//  TO insert Data
void insert()
{
     struct node *temp;
     temp = (struct node*) malloc (sizeof(struct node));
     printf("Enter data \n");
     scanf("%s",temp->data);

    if(root==NULL)
     {
        root=temp;
     }
    else
     {
          struct node *p;
         p=root;
         while(p->right!=NULL)
         {
             p=p->right;
         }
         p->right=temp;
         temp->left=p;
     }
}
   // To Display Data
void display()
{
        struct node *p;
         p=root;
         while(p!=NULL)
         {
             printf("  %s  ",p->data);
             p=p->right;
         }
}
struct node *p=NULL;

    // To Traverse Data to Right
void forward()
{

if(p==NULL)
  {
      p=root;
      printf("                                                    %s",p->data);
  }
else
  {
      p=p->right;
      printf("                                                    %s",p->data);
  }

}
      // To Traverse Data to Left
void backward()
{
    p=p->left;
    printf("                                                    %s",p->data);
}
       //To delete Data
void deletion()
{
    struct node *temp;
    if(p==NULL)
    {
        printf("                                                    Empty!!");
    }
    else if(p->left==NULL)
    {
        temp=root;
        root=root->right;
        root->left=NULL;
        printf("                                                    %s is Deleted\n",p->data);
        free(temp);

    }
    else if(p->right==NULL)
    {
        printf("                                                    %s is Deleted\n",p->data);
        temp=p;
        p->left->right=NULL;
        p=p->left;
        free(temp);
    }
    else
    {
       printf("                                                    %s is Deleted\n",p->data);
       temp=p;
       p->left->right=p->right;
       p->right->left=p->left;
       free(temp);
    }
}
int main()
{
  int a;
  int y=0;
 while(y<100)
 {
    printf("\nPress 1 for Insert\nPress 2 for Display\nPress 3 to go Right\nPress 4 to go Left\nPress 5 to delete\n");
    scanf("%d",&a);

    switch(a)
    {
        case 1: insert();
        break;
        case 2: display();
        break;
        case 3: forward();
        break;
        case 4: backward();
        break;
        case 5: deletion();
        break;
        default: printf("Invalid Input!!\n");
    }
 }
    return 0;
}

