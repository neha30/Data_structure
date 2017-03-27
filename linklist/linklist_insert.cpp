#include<iostream>
#include<stdlib.h>
#include "linklist_utilities.h"

using namespace std;

int main(int argc, char const *argv[])
{
	struct node *head=NULL;
	int n;
	int del_element;
	int value;
	cout<<"enter total number of nodes: ";
	cin>>n;

	cout<<"\nenter node values: \n";
	for(int i=0;i<n;i++)
	{
		cin>>value;
		head=insert_node(value,head);
	}

	cout<<"\nelement of linklist are:\n";
	print_linklist(head);

	cout<<"enter element you want to delete: ";
	cin>>del_element;

	head=delete_node(del_element,head);

	cout<<"\nlinklist after deletion:\n";
	print_linklist(head);
	return 0;
}

