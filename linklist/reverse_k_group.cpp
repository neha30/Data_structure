#include<iostream>
#include "linklist_utilities.h"

using namespace std;

struct node  *ReverseKGroup(int n,int k,struct node *head)
{
	struct node *prev=NULL,*current=head,*next=NULL;
	int count=0;

	while(current!=NULL && count<k)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		count++;
	}

	if(next!=NULL)
	{
		head->next=ReverseKGroup(n,k,next);
	}

	return prev;
}


int main(int argc, char const *argv[])
{
	struct node *head=NULL;
	int n,k;
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

	cout<<"\nenter value of k:";
	cin>>k;

	head=ReverseKGroup(n,k,head);

	cout<<"\nelement after reverse in  group of k\n";
	print_linklist(head);
	return 0;
}