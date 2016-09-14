//program to find the minimum value in BST

#include<iostream>
#include "BST_utilities.h"

using namespace std;

//function for finding the min value
void find_min(struct node *root)
{
    if(!root)
   	    return;
   	
   	while(root->left!=NULL)
   		root=root->left;

    cout<<root->data;

}

int main(int argc, char const *argv[])
{
	int total,r;
	struct node *head=NULL;

	cout<<"enter total node: ";
	cin>>total;

	cout<<"\nenter range for node value: ";
	cin>>r;

	//call function to generate BST
  head=generate_BST(total,r);

  //call function to print the tree
  print_BST(head);

  //call function to find min value in BST
  cout<<"min value is:";
  find_min(head);
  cout<<endl;

	return 0;
}