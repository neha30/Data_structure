#include<iostream>
#include<stdlib.h>
#include "linklist_utilities.h"

using namespace std;

//Function to reverse linklist
//p---> point to previous node
//q---> point to current node
//r---> point to next node
struct node *Reverse(struct node *root)
{
	struct node *p,*q,*r;
	p=r=NULL;
	q=root;
	while(q!=NULL)
	{
		r=q->next;
		q->next=p;
		p=q;
		q=r;
	}

	return p;
}

int main(int argc, char const *argv[])
{
	struct node *head=NULL;
	int total, value;
	cout<<"enter total number of nodes: ";
	cin>>total;

	cout<<"\nenter node values: \n";
	for(int i=0;i<total;i++)
	{
		cin>>value;
		head=insert_node(value,head);
	}

	cout<<"\nelement of linklist are:\n";
	print_linklist(head);

	head=Reverse(head);

	cout<<"\nlinklist list after reverse operation:\n";
	print_linklist(head);
	return 0;
}