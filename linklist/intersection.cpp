#include<iostream>
#include "linklist_utilities.h"

using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	struct node *head1=NULL,*head2=NULL;
	int n,m, value,count=1,pos; //n->total nodes in first linklist and m-> total nodes in second linklist

	cout<<"enter total number of nodes of first linklist: ";
	cin>>n;

	cout<<"\nenter node values: \n";
	for(int i=0;i<n;i++)
	{
		cin>>value;
		head1=insert_node(value,head1);
	}

	cout<<"\nelement of first linklist are:\n";
	print_linklist(head1);

	cout<<"enter total number of nodes of second linklist: ";
	cin>>n;

	cout<<"\nenter node values: \n";
	for(int i=0;i<n;i++)
	{
		cin>>value;
		head2=insert_node(value,head2);
	}

	cout<<"\nelement of second linklist are:\n";
	print_linklist(head);

	cout<<"\nposition in first list to join both the list:";
	cin>>pos;

	struct node *temp=head1;
	while(count!=pos)
	{
		temp=temp->next;
		count++;
	}

	//join the second list with the temp address
	struct node *end=head;
	while(end->next)

	return 0;
}