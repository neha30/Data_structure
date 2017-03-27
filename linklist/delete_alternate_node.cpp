#include<iostream>
#include "linklist_utilities.h"

using namespace std;

int DeleteAlternate(struct node *head,int n)
{
	struct node *temp1=head,*temp2=head;
	struct node *head1=head,*head2=head->next;

	temp2=temp1->next;  //temp1 will point to first node and temp2 will point to second node in list
	while(temp1!=NULL && temp2!=NULL || temp1->next!=NULL &&temp2->next!=NULL)
	{
		temp1->next=temp1->next->next;
		temp1=temp1->next;
		temp2->next=temp1->next;
		temp2=temp2->next;
	}


	//print both the list
	cout<<"\nfirst list is\n";
	print_linklist(head1);

	cout<<"\nsecond list is: \n";
	print_linklist(head2);
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

	DeleteAlternate(head,n);

	return 0;
}