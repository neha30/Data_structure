#include<iostream>
#include<map>
#include "linklist_utilities.h"

using namespace std;

//method-1
//1 When we know the total length on linklist then traverse the list again upto total length-nth position.
// TC=O(n)+O(n)=O(n)
//SC=O(1)
void nthNodeEnd_TotalLength(int total,int n,struct node *head)
{
	struct node *temp=head;
	if(n<=total)
	{
		int count=1;
		while(count<=total-n)
		{
			temp=temp->next;
			count++;
		}

		cout<<"nth node from end is: "<<temp->data;<<"\n"
	}
	else
		cout<<"invalid value of n \n";


	return;
}

//using hashmap
//1 create the hash table whose entries are <position of node,node address>. That means, key is the position of node and value is the 
//  address of that node. 
//2 By the time we traverse the complete list(for creating hash table), we can find the list length.
//3 Now  return m-n+1th key value from the table.
// TC=O(m)
//SC=O(m)

void nthNodeEnd_HashMap(struct node *head)
{
	map<int, struct node *> myMap;
	int count=1;  //to keep track of current node position from start
	struct node *temp=head;

	while(temp)
	{
		myMap[count]=temp;
		count++;
		temp=temp->data;
	}

}


int main(int argc, char const *argv[])
{
	struct node *head=NULL;
	int total, value,n;
	cout<<"enter total number of nodes: ";
	cin>>total;

	cout<<"\nenter node values: \n";
	for(int i=0;i<total;i++)
	{
		cin>>value;
		head=insert_node(value,head);
	}

	cout<<"\nelement of linklist are:\n";
	print_linklist(head);

	cout<<"enter nth node from end: ";
	cin>>n;
	
	nthNodeEnd_TotalLength(total,n,head);
	return 0;	
}
