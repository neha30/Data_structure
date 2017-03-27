#include<iostream>
#include<stdlib.h>
#include "linklist_utilities.h"

using namespace std;


struct node *IntersectionSortedLinklist(struct node *head1,struct node *head2)
{
	if(head1==NULL || head2==NULL)
		return NULL;

	if(head1->data<head2->data)
		return IntersectionSortedLinklist(head1->next,head2);

	if(head1->data>head2->data)
		return IntersectionSortedLinklist(head1,head2->next);

	
	
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=head1->data;
	newnode->next=IntersectionSortedLinklist(head1->next,head2->next);
	
	return newnode;

}


int main(int argc, char const *argv[])
{
	struct node *head1=NULL,*head2=NULL;
	struct node *head3=NULL; //head pointer  to the resulted  linklist
	int n1,n2;
	int value;

	//first sorted linklist
	cout<<"enter total number of nodes in first linklist: ";
	cin>>n1;

	cout<<"\nenter node values: \n";
	for(int i=0;i<n1;i++)
	{
		cin>>value;
		head1=insert_node(value,head1);
	}

	cout<<"\nelement of first linklist are:\n";
	print_linklist(head1);

	//Second sorted linklist
	cout<<"enter total number of nodes in second linklist: ";
	cin>>n2;

	cout<<"\nenter node values: \n";
	for(int i=0;i<n2;i++)
	{
		cin>>value;
		head2=insert_node(value,head2);
	}

	cout<<"\nelement of second linklist are:\n";
	print_linklist(head2);

	head3=IntersectionSortedLinklist(head1,head2);

	cout<<"\nintersection of two list are:\n";
	print_linklist(head3);

	return 0;
}