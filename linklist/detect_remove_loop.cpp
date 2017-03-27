//Write a function detectAndRemoveLoop() that checks whether a given Linked List contains loop and if loop is present then removes the
// loop and returns true. And if the list doesn’t contain loop then returns false. Below diagram shows a linked list with a loop. 
// detectAndRemoveLoop() must change the below list to 1->2->3->4->5->NULL.

#include<iostream>
#include "linklist_utilities.h"

using namespace std;

int detectAndRemoveLoop(struct node *head)
{
	struct node *slowPtr=head,*fastPtr=head;
	int loopExist=0;


	while(slowPtr && fastPtr)
	{
		fastPtr=fastPtr->next;

		if(fastPtr==slowPtr)
		{
			loopExist=1;
			break;
		}

		if(fastPtr==NULL)
		{
			loopExist=0;
			break;
		}

		fastPtr=fastPtr->next;

		if(fastPtr==slowPtr)
		{
			loopExist=1;
			break;
		}
	}
	
	//code for finding the start node of loop
	if(loopExist)
	{
		slowPtr=head;
		while(slowPtr!=fastPtr)
		{
			slowPtr=slowPtr->next;
			fastPtr=fastPtr->next;
		}
		return  slowPtr->data;
	}
	return 0;

}


int main(int argc, char const *argv[])
{
	struct node *head=NULL;
	int n,pos;
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

	//cout<<"\nenter the position:";
	//cin>>pos;

	struct node *end=head,*temp=head;

	while(end->next!=NULL)
		end=end->next;


	end->next=head->next->next;
	//int count=1;
	//while(count!=pos)
	//{
	//	temp=temp->next;
	//	count++;
	//}

	//make the loop in the linklist
	

	int result=detectAndRemoveLoop(head);
	if(result)
		cout<<"\nloop is present and start element of loop is: "<<result<<"\n";
	else
		cout<<"loop is not present\n";
	

	return 0;
}