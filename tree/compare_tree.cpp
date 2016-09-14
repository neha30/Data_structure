//program to compare two tree and return true if they are struturally identical.

#include<iostream>
#include<queue>
#include "tree_utilities.h"

using namespace std;

int identicalTrees(struct node* a, struct node* b)
{
    /*1. both empty */
    if (a==NULL && b==NULL)
        return 1;
 
    /* 2. both non-empty -> compare them */
    if (a!=NULL && b!=NULL)
    {
        return
        (
            a->data == b->data &&
            identicalTrees(a->left, b->left) &&
            identicalTrees(a->right, b->right)
        );
    }
     
    /* 3. one empty, one not -> false */
    return 0;
} 

int main(int argc, char const *argv[])
{
   struct node *head1;
   struct node *head2;
   int total,r,max,count,val;


   //take input from user
   cout<<"enter total nodes for first tree:\n";
   cin>>total;

   //take input from user
   cout<<"enter range for node value for first tree:\n";
   cin>>r;

   //call function to build the tree
   head1=generate_tree(total,r);

      //take input from user
   cout<<"enter total nodes for second tree:\n";
   cin>>total;

   //take input from user
   cout<<"enter range for node value for second tree:\n";
   cin>>r;

   //call function to build the tree
   head2=generate_tree(total,r);

   //print generated tree in preorder form
   cout<<"\nfirst tree preorder traversal is:\n";
   print_tree1(head1);

   //print the tree (inorder)
   cout<<"\nfirst tree inorder traversal is:\n";
   print_tree2(head1);

   cout<<"\nsecond tree preorder traversal is:\n";
   print_tree1(head2);

   //print the tree (inorder)
   cout<<"\nsecond tree inorder traversal is:\n";
   print_tree2(head2);

   val=identicalTrees(head1,head2);

   if(val)
   	  cout<<"\nTrees are identical"<<endl;
   	else
   	  cout<<"\nTrees are not identical"<<endl;
   
	return 0;
}  