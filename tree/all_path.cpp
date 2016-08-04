//Program to print all path from root to leaf node

#include<iostream>
#include "tree_utilities.h"

using namespace std;

void print_path(int *path,int pathlen)
{

	int i;
	cout<<"\npath is:\n";
	for(i=0;i<pathlen;i++)
	{
		cout<<path[i]<<" ";
	}
}

void all_path(struct node *root,int *path,int pathlen)
{
   if(!root)
   	  return;

   	//append node to the path array
   	path[pathlen]=root->data;
   	pathlen++;

   	//if it's a leaf,print the path that led to here
   	if(!root->left && !root->right)
   		print_path(path,pathlen);
   	else
   	{
   		//otherwise try both subtreee
   		all_path(root->left,path,pathlen);
   		all_path(root->right,path,pathlen);
   	}

}

int main(int argc, char const *argv[])
{
   struct node *head;
   int total,r,result;
   //This will contain the path in tree
   int path[100];

   //take input from user
   cout<<"enter total nodes:\n";
   cin>>total;

   //take input from user
   cout<<"enter range for node value:\n";
   cin>>r;

   //call function to buld the tree
   head=generate_tree(total,r);

   //print generated tree in preorder form
   cout<<"\n preorder traversal of tree is:\n";
   print_tree1(head);

   //print the tree (inorder)
   cout<<"\ninorder traversal of tree is:\n";
   print_tree2(head);

   //call function to print all path, here 0 will indicate initial path length 
   all_path(head,path,0);
	return 0;
}
