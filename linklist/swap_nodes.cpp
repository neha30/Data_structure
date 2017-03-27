#include<iostream>
#include<stdlib.h>
#include "linklist_utilities.h"

using namespace std;

void SwapNodes(int x,int y,struct node *head)
{
	struct node *prevx=NULL,*currx=head;	//previuos and current node pointer to x
	struct node *prevy=NULL,*curry=head;   //previous and current node pointer to y

	if(x==y)
		return;

	while(currx && currx->data!=x)
	{
		prevx=currx;
		currx=currx->next;
	}

	while(curry && curry->data!=y)
	{
		prevy=curry;
		curry=curry->next;
	}

	//if either of x or y is not present in the list
	if(currx==NULL || curry=NULL)
	{
		cout<<"element not present in the list";
		return;
	}

	//

}

int main(int argc, char const *argv[])
{
	//x and y are the element whixh we want to swap
	int n,x,y;
	struct node *head=NULL;

	cout<<"enter total number of nodes: ";
	cin>>n;

	cout<<"\nenter node values: \n";
	for(int i=0;i<n;i++)
	{
		cin>>value;
		head=insert_node(value,head);
	}

	cout<<"\nenter node you want to swap: ";
	cin>>x>>y;

	SwapNodes(x,y,head);

	return 0;
}