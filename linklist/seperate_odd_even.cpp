//Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.

//Examples:
//Input: 17->15->8->12->10->5->4->1->7->6->NULL
//Output: 8->12->10->4->6->17->15->5->1->7->NUL

#include<iostream>
#include "linklist_utilities.h"

using namespace std;

struct node *seperateEvenOddNode(struct node *head,int n)
{
	struct node *temp=head;
	struct node *end=head;
	struct node *curr=head;
	struct node *prev=head;
	//end will point to the last node
	while(end->next!=NULL)
		end=end->next;

	int count=0;

	while(count!=n)
	{
		if(temp->data%2!=0 && head==temp)
		{
			prev=temp;
			curr=temp;
			head=head->next;
			temp=temp->next;
			end->next=curr;
			curr->next=NULL;
			count++;
			end=end->next;
		}
		else if(temp->data%2!=0)
			{
				curr=temp;
				temp=temp->next;
				prev->next=temp;
				end->next=curr;
				curr->next=NULL;
				count++;
				end=end->next;
			}
		
		else
		{
			prev=temp;
			temp=temp->next;
			count++;
		}

	}
	return head;
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

	head=seperateEvenOddNode(head,n);

	cout<<"\nelement of linklist after seperation:\n";
	print_linklist(head);
	return 0;
}