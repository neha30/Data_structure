#include<iostream>
#include<malloc.h>
#include<stack>
#include<queue>
#include "tree_utilities.h"

using namespace std;


//preorder non recursive 
void preorder_NR(struct node *root)
{
  stack<struct node *> s;
  while(1)
  {
        while(root)
        {
              //process current node
              cout<<root->data<<"\n";
              s.push(root);
              //if left subtree exist, add to stack
              root=root->left;
        }
        if(s.empty())
            break;
        root=s.top();
        s.pop();
        //indicate completeion of left subtree and current node, go to right subtree
        root=root->right;
  }
  

}

//inorder non recursive
void inorder_NR(struct node *root)
{
   stack<struct node *> s;
   while(1)
   {
         while(root)
         {
              s.push(root);
              //got left subtree and keep on adding to stack
              root=root->left;              
         }
         if(s.empty())
           break;
         root=s.top();
         //process the current node
         cout<<root->data<<"\n";
         s.pop();
         //indicate completion of left subtree and current node, now go to right subtree
         root=root->right;
   }
}

//level order non recursive
void levelorder_NR(struct node *root)
{
   struct node *temp;
   queue<struct node *> q;
   if(!root)
         return;
   q.push(root);
   while(!q.empty())
   {
         temp=q.front();
         q.pop();
         cout<<temp->data<<"\n";
         if(temp->left)
                q.push(temp->left);
         if(temp->right)
                q.push(temp->right);
   }
}

//postorder non recursive
void postorder_NR(struct node *root)
{
  stack<struct node *> s;
  
  //check for empty stack
  if(!root)
      return;

   do
   {
       while(root)
       {
              //push root's right child and then root
              if(root->right)
                   s.push(root->right);
              s.push(root);
 
              //set root as root's left child
              root=root->left;
       }

       //pop an item fro the stack and set it as a root
       root=s.top();
       s.pop();
      
       //if the popped item has the right child and the right child is not
       //processed yet, then make sure right child is processed brfore root
       if(root->right&&s.top()==root->right)
       {
             s.pop();
             s.push(root);
             root=root->right;
       }
       else
       {
             cout<<root->data<<"\n";
             root=NULL;
       }
   }while(!s.empty());

}

//main start here
int main()
{
   struct node *head=NULL;
   int total,r;
 
   cout<<"enter total number of nodes:\n";
   cin>>total;

   cout<<"enter range for node value:\n";
   cin>>r;

   //call function to build the tree
   head=generate_tree(total,r);

   //call function to print the tree
   print_tree1(head);

   //call function to print tree
   cout<<"\ntree is:\n";
   print_tree2(head);

   //call function to print preorder
   cout<<"\npreorder traversal is:\n";
   preorder_NR(head);

   //call function to print inorder traversal
   cout<<"\ninorder traversal\n";
   inorder_NR(head);

   //call function to print level order traversal
   cout<<"level order traversal is\n";
   levelorder_NR(head);

   //call function to print postorder traversal
   cout<<"postorder traversal is\n";
   postorder_NR(head);
   
   return 0;
}
