#include<iostream>
#include<map>
#include "linklist_utilities.h"

using namespace std;


//We traverse the link list from head to end. For every newly encountered element, we check whether it is in the hash table: 
//if yes, we remove it; otherwise we put it in the hash table.
int RemoveDuplicates(int n,struct node *head)
{
	map<int,int> myMap;
	struct node *temp=head,*prev=NULL;

	//create the hashtable iterator
	//map<int,int>::iterator it;

	while(temp!=NULL)
	{
		//check whether the current node data is present in hashtable or not
		if(myMap.find(temp->data)!=myMap.end())   //if yes means data is present in hashtable
		{
			prev->next=temp->next;
			temp=temp->next;
		}
		else
		{
			myMap[temp->data]=1;
			prev=temp;
			temp=temp->next;
		}
	}
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

	RemoveDuplicates(n,head);

	cout<<"\nelement of linklist are deletng duplicates:\n";
	print_linklist(head);
	return 0;
}