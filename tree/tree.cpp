//to insert a element in binary tree we can use level order traversal and insert the element wherever we found the node whose left child is NULL

#include<iostream>
#include<malloc.h>
#include "tree_utilities.h"

using namespace std;

int main()
{
  int total,r;
  struct node *head=NULL;

  cout<<"enter total number of nodes:\n";          
  cin>>total;

  cout<<"\nenter the range for node value:\n";
  cin>>r;

  //calling function to build the tree
  head=generate_tree(total,r);
  

  //print the tree (preorder)
  cout<<"\ntree is:\n";
  print_tree1(head);

  //print the tree (inorder)
  cout<<"\ntree is:\n";
  print_tree2(head);
 
  return 0;
}
