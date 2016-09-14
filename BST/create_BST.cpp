//program to create BST

#include<iostream>
#include "BST_utilities.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int total,r;
	struct node *head=NULL;

	cout<<"enter total nodes for BST: ";
	cin>>total;

	cout<<"\nenter range for value of node: ";
	cin>>r;

    head=generate_BST(total,r);

    print_BST(head);
    cout<<endl;
	return 0;
}