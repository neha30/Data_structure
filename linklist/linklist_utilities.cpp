#include<iostream>
#include<stdlib.h>
#include "linklist_utilities.h"

//insert element in linklist from last
struct node *insert_node(int value,struct node *head)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->next=NULL;

	//insert the node in the last
	if(!head)
		return newnode;
	else
	{
		struct node *temp=head;
		while(temp->next!=NULL)
			temp=temp->next;

		temp->next=newnode;
		return head;
	}
}

//to print the linklist element
void print_linklist(struct node *head)
{
	struct node *temp=head;
	while(temp)
	{
		std::cout<<temp->data<<"-->";
		temp=temp->next;
	}
	std::cout<<"\n";
}

//delete node from linklist
struct node *delete_node(int value,struct node *head)
{
	struct node *temp=head,*prev;

	//if first node contain the element which we want to delete
	if(temp!=NULL && temp->data==value)
	{
		head=temp->next;
		free(temp);
		return head;
	}

	//finally temp will point to node to be deleted and prev will point to its previous node
	while(temp!=NULL && temp->data!=value)
	{
		prev=temp;
		temp=temp->next;
	}

	//if key was not present in the list
	if(temp==NULL)
	{
		std::cout<<"element not present\n";
		return head;
	}

	prev->next=temp->next;
	free(temp);
	return head;

}