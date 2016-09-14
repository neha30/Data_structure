//Program for merging two BST

#include<iostream>
#include "BST_utilities.h"

using namespace std;



int main(int argc, char const *argv[])
{
	int total,r,key;
	struct node *head1=NULL;
	struct node *head2=NULL;

    //------------------------------first BST----------------------//
	cout<<"enter total node for first BST: ";
	cin>>total;

	cout<<"\nenter range for node value for first BST: ";
	cin>>r;

    
	//call function to generate BST
    head1=generate_BST(total,r);

    //call function to print the tree
    print_BST(head1);

    //------------------------------second BST-----------------------//
    cout<<"enter total node for second BST: ";
	cin>>total;

	cout<<"\nenter range for node value for second BST: ";
	cin>>r;

	//call function to generate BST
    head2=generate_BST(total,r);
  
    //call function to print the tree
    print_BST(head2);

    merge_BST(head1,head2);




	return 0;
}