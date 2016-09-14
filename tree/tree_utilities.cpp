#include<iostream>
#include "tree_utilities.h"
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<queue>

struct node *build_tree(int value,struct node *root)
{
  //declare a queue
  std::queue<struct node *> q;
  
  //create the new node
  struct node *temp;
  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  newnode->left=NULL;
  newnode->right=NULL;
  newnode->data=value;

  if(!newnode)
  {
       std::cout<<"node not created\n";
       return NULL;
  }
  if(!root)
  {
       root=newnode;
       return root;
  }
  
  //level order traversal for inserting the element
  q.push(root);
  while(!q.empty())
  {
       temp=q.front();
       //cout<<"\nvalue of temp is:%d"<<temp;
       q.pop();
       if(temp->left)
            q.push(temp->left);
       else
       {
           temp->left=newnode;
           return root;
       }
     
       if(temp->right)
           q.push(temp->right);
       else
       {
          temp->right=newnode;
          return root;
       }
  }
  
  return root;
}

//Function to create tree of n node in range 0 to r-1
struct node *generate_tree(int total,int r)
{
        struct node *head;
        int i,value;
        time_t t;
        //initialize random number generator
        srand((unsigned)time(&t));
        for(i=0;i<total;i++)
        {
             value=rand()%r;
             head=build_tree(value,head);
        }       
        return head;
}

//function to print tree (preorder trversal)
void print_tree1(struct node *root)
{
  if(root)
  {
     std::cout<<root->data<<"\n";
     print_tree1(root->left);
     print_tree1(root->right);
  }
}

//function to print tree (inorder traversal)
void print_tree2(struct node *root)
{

  if(root)
  {

    print_tree2(root->left);
    std::cout<<root->data<<"\n";
    print_tree2(root->right);
  }
}
