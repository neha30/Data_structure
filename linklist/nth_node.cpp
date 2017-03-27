#include<iostream>
#include<stdlib.h>
#include "linklist_utilities.h"

using namespace std;

void NthNode(int n,int total,struct node *head)
{
	struct node *temp=head;
	if(n>total)
	{
		cout<<"Out of index\n";
		return;
	}
	int i=1;
	while(i!=n)
	{
		temp=temp->next;
		i++;
	}

	cout<<temp->data<<"\n";
}

int main(int argc, char const *argv[])
{
	int n,total,value;
	struct node *head=NULL;

	cout<<"enter total number of nodes: ";
	cin>>total;

	cout<<"\nenter node values: \n";
	for(int i=0;i<total;i++)
	{
		cin>>value;
		head=insert_node(value,head);
	}

	cout<<"enter the node number: ";
	cin>>n;

	NthNode(n,total,head);


	return 0;
}