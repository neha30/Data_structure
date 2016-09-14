//program fro finding least common ancestor(LCA) of two keys.
//This program can also be used for finding shortest path between two node in BST

#include<iostream>
#include "BST_utilities.h"

using namespace std;

int find_lca(struct node *root,int key1,int key2)
{
	if(!root)
		return 0;

    //if both the key are smaller then root->data
	if(key1<root->data && key2<root->data)
		return find_lca(root->left,key1,key2);
	else
	//if both the key greater then root->data
	if(key1>root->data && key2>root->data)
		return find_lca(root->right,key1,key2);
	
	return root->data;
}

int main(int argc, char const *argv[])
{
	int total,r,key1,key2,result;
	struct node *head=NULL;

	cout<<"enter total node: ";
	cin>>total;

	cout<<"\nenter range for node value: ";
	cin>>r;

	//call function to generate BST
    head=generate_BST(total,r);

    //call function to print the tree
    print_BST(head);

    cout<<"\nenter first key: ";
    cin>>key1;

    cout<<"\nenter second key: ";
    cin>>key2;

    //call function for finding LCA
    result=find_lca(head,key1,key2);
    cout<<"LCA is: "<<result<<endl;
	
	return 0;
}