//Program to find the maximum element in Binary tree. This program contain both recursive and non-recusive function for performing this operation.

#include<iostream>
#include "tree_utilities.h"
#include<queue>
#include<limits.h>

using namespace std;

//recursive function for finding the max element in the 
int find_max_recursive(struct node *root)
{
   int left,right,max;
   if(!root)
     return -1;

   left=find_max_recursive(root->left);
   right=find_max_recursive(root->right);

   //find the larger of the three value(root, left child, right child)
   if(left>right)
          max=left;
   else
          max=right;
   if(root->data>max)
          return root->data;
   else
          return max;
   

}

//non recursive function for finding the max element (using queue)
int find_max_NonRecursive(struct node *root)
{
   int max=INT_MIN;
   struct node *temp;

   queue<struct node *> q;
 
   q.push(root);
   while(!q.empty())
   {
      temp=q.back();
      q.pop();

      //largest of the three value
      if(temp->data>max)
             max=temp->data;
      if(temp->left)
             q.push(temp->left);
      if(temp->right)
             q.push(temp->right);
   }

   return max;   

}

int main()
{
   struct node *head;
   int total,r,max;

   //take input from user
   cout<<"enter total nodes:\n";
   cin>>total;

   //take input from user
   cout<<"enter range for node value:\n";
   cin>>r;

   //call function to buld the tree
   head=generate_tree(total,r);

   //print generated tree in preorder form
   cout<<"\ntree is:\n";
   print_tree1(head);

   //print the tree (inorder)
   cout<<"\ntree is:\n";
   print_tree2(head);

   //call function to find maximum element in the binary tree
   max=find_max_recursive(head);
   cout<<"max element using recursive function : "<<max<<"\n";

   //call non recursive function to find max element in the binary tree
   max=find_max_NonRecursive(head);
   cout<<"\nmax element using non recursive function : "<<max<<"\n";
   return max;
}
