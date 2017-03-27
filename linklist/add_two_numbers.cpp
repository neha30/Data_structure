//Given two numbers represented by two lists, write a function that returns sum list. The sum list is list representation of
//addition of two input numbers.

#include<stdlib.h>
#include<iostream>
#include "linklist_utilities.h"

using namespace std;

struct node *addTwoNumbers(struct node *head1,struct node *head2)
{
	//this will be the head pointer or resultant node
	struct node *head3=NULL;
	struct node *temp1=head1,*temp2=head2,*temp3; //this pointer will point to the current node of all the three linklist
	int carry=0,add;

	while(temp1&&temp2)
	{
		//create newnode of resultant list
		struct node *newnode=(struct node *)malloc(sizeof(struct node));
		
		add=(temp1->data)+(temp2->data);
		newnode->data=(add+carry)%10;
		//cout<<"newnode=>data:"<<newnode->data<<"\n";
		newnode->next=NULL;

		carry=(add+carry)/10;
		cout<<"carry:"<<carry<<"\n";
		//cout<<"carry:"<<carry<<"\n";
		//cout<<"temp1->data:"<<temp1->data<<"\n";
		//cout<<"temp2->data:"<<temp2->data<<"\n";

		if(!head3) 
		{
			//this is the first node of resultant list
			head3=newnode;
			temp3=head3;   //temp3 will point to the current node of resultant list
		
		}
		else
		{
			//append the node in the last position of resultant list
			temp3->next=newnode;
			temp3=temp3->next;

		}
		
		temp1=temp1->next;
		temp2=temp2->next;
	}

	int data;
	if(temp1)
	{
		while(temp1!=NULL)
		{
			struct node *newnode=(struct node *)malloc(sizeof(struct node));
			data=temp1->data;
			newnode->data=(temp1->data+carry)%10;
			newnode->next=NULL;
			carry=(data+carry)/10;
			temp3->next=newnode;
			temp3=temp3->next;
			temp1=temp1->next;
		}
	}

	if(temp2)
	{
		while(temp2!=NULL)
		{
			struct node *newnode=(struct node *)malloc(sizeof(struct node));
			data=temp2->data;
			newnode->data=(temp2->data+carry)%10;
			newnode->next=NULL;
			carry=(data+carry)/10;
			temp3->next=newnode;
			temp3=temp3->next;
			temp2=temp2->next;
		}
	}

	return head3;
}

int main(int argc, char const *argv[])
{
	struct node *head1=NULL,*head2=NULL,*head3;
	int n1,n2;
	int value;
	cout<<"enter total number of nodes for first list: ";
	cin>>n1;

	cout<<"\nenter node values for first list: \n";
	for(int i=0;i<n1;i++)
	{
		cin>>value;
		head1=insert_node(value,head1);
	}

	cout<<"\nelement of linklist are:\n";
	print_linklist(head1);

	cout<<"enter total number of nodes for second list: ";
	cin>>n2;

	cout<<"\nenter node values for second list: \n";
	for(int i=0;i<n2;i++)
	{
		cin>>value;
		head2=insert_node(value,head2);
	}

	cout<<"\nelement of linklist are:\n";
	print_linklist(head2);
	
	head3=addTwoNumbers(head1,head2);

	cout<<"\naddition of two numbers is\n";
	print_linklist(head3);

	return 0;
}