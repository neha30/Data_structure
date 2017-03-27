
#include<iostream>
#include<stdlib.h>
#include<list>

using namespace std;

//create structure
struct node
{
	string data;
	struct node *next;
};

//function to insert node at back
struct node *insertNode(struct node *head,string value)
{
	struct node *newnode=new node;
	newnode->data=value;
	newnode->next=NULL;

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

void printList(struct node *head)
{
	struct node *temp=head;

	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}

int checkPalindrome(struct node *head)
{
	//append all the nodes to form string
	string str="";
	while(head!=NULL)
	{
		str.append(head->data);
		head=head->next;
	}

	int length=str.length();
	//match character from beginning and end
	for(int i=0;i<length;i++)
	{
		if(str[i]!=str[length-i-1])
			return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int n;
	string value;
	struct node *head=NULL;

	cout<<"enter total no. of nodes:";
	cin>>n;

	cout<<"enter element:";
	for(int i=0;i<n;i++)
	{
		cin>>value;
		head=insertNode(head,value);
	}

	cout<<"list is:\n";
	printList(head);

	//call function to check for palindrome
	if(checkPalindrome(head))
		cout<<"palindrome\n";
	else
		cout<<"not palindrome\n";
	
	return 0;
}