#include<iostream>
#include<stdlib.h>
#include<time.h>
#include "BST_utilities.h"


struct node *build_BST(struct node *root,int value)
{
   //create new node
   struct node *newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data=value;
   newnode->left=NULL;
   newnode->right=NULL;

   //if tree is empty,return the newnode
   if(!root)
   	  return newnode;

   //otherwise recurs down the tree to find the location for inserting new node
   if(value<root->data)
   	   root->left=build_BST(root->left,value);
    else
       root->right=build_BST(root->right,value);
    
   return root;
}

///function to generate BST
struct node *generate_BST(int total,int r)
{
	struct node *head=NULL;
	int i,value;
	time_t t;

    //initialize random generator
    srand((unsigned)time(&t));

	//loop to generate values
	for(i=0;i<total;i++)
	{
		value=rand()%r;
		head=build_BST(head,value);
	}


	return head;
}


//function for printing BST (preorder)
void print_BST(struct node *root)
{
   if(root)
   {
       std::cout<<root->data<<" ";
       print_BST(root->left);
       print_BST(root->right);
   }

}

//function for searching key in BST
struct node *search(struct node *root,int key)
{
  if(!root)
      return NULL;
  else
  if(key==root->data)
      return root;
  else
  if(key<root->data)
      search(root->left,key);
  else
      search(root->right,key);

}







