#include<iostream>
#include "linklist_utilities.h"
#include<math.h>	//ceil

using namespace std;


void reverse(struct node *head,int total,int middle)
{
	int count=0;
	struct node *p=NULL,*q=NULL,*r=NULL;
	struct node *temp=head;


	//temp will point out to the node after which reversal is done
	while(count!=(middle-1))
	{
		temp=temp->next;
		count++;
	}

	//p-->point to previous node
	//q-->point to current node
	//r-->point to next node
	q=temp->next;
	while(q!=NULL)
	{
		r=q->next;
		q->next=p;
		p=q;
		q=r;
	}
	temp->next=p;

}

int palindrome(struct node *head,int length)
{
	int middle;
	int count=0;
	struct node *temp1=head,*temp2=head;	//temp1 will keep track from start of node and temp2 from middle of node


	if(length%2==0)
		middle=length/2;
	else
		middle=(length/2)+1;

	//reverse the half of the linklist
	reverse(head,length,middle);

	cout<<"\nlinklist after reverse:\n";
	print_linklist(head);



	while(count!=middle)
	{
		temp2=temp2->next;
		count++;
	}

	//compare the two halves
	while(temp2!=NULL)
	{
		if(temp1->data==temp2->data)
		{
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else
		{
			cout<<"\nnot palindrome\n";
			return 0;
		}
	}

	cout<<"\npalindrome\n";
	return 0;

	
}

int main(int argc, char const *argv[])
{
	struct node *head=NULL;
	int n, value;

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

	palindrome(head,n);
	return 0;
}