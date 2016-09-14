//program for checking whether given binary tree is BST or not.

#include<iostream>
#include "BST_utilities.h"

using namespace std;

int check(struct node *root)
{
    
}

int main(int argc, char const *argv[])
{
	int total,r,choice;
	struct node *head=NULL;

	cout<<"enter total node: ";
	cin>>total;

	cout<<"\nenter range for node value: ";
	cin>>r;

	//call function to generate BST
    head=generate_BST(total,r);

    //call function to print the tree
    print_BST(head);

    cout<<"choose 1 if you want to generate BT and 0 to generate BST: ";
    cin>>choice;

    if(choice)
    {
    	head=generate_tree(total,r);
    	print_tree1(head);
    	print_tree2(head);
    }
    else
    {
    	head=generate_BST(total,r);
    	print_BST(head);
    }

    //call function for checking whther given binary tree is BST or not
    check(head);
	return 0;
}