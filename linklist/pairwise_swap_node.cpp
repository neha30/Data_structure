#include<iostream>
#include "linklist_utilities.h"

using namespace std;

int PairwiseSwap(int n,struct node *head)
{
	struct node *temp=head;
	int data;

	while(temp!=NULL && temp->next!=NULL)
	{
		data=temp->data;
		temp->data=temp->next->data;
		temp->next->data=data;

		temp=temp->next->next;
	}
}

int main(int argc, char const *argv[])
{
	struct node *head=NULL;
	int n;
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

	PairwiseSwap(n,head);

	cout<<"\nelement of linklist after pairwise swap:\n";
	print_linklist(head);	


	return 0;
}