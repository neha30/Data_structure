//program for deleting node from BST

#include<iostream>
#include<stdlib.h>
#include "BST_utilities.h"

using namespace std;

//function for finding max value node in BST
struct node *find_max(struct node *root)
{
	if(!root)
		return NULL;
	else
	if(!root->right)
		return root;
	else
	return find_max(root->right);
}

//function for deleting node from BST
struct node *delete_node_BST(struct node *root,int data)
{
    struct node *temp;

    //base case
    if(!root)
    	cout<<"element not there in tree"<<endl;
    else
    //finding the node which we want to delete
    if(data<root->data)
    	root->left=delete_node_BST(root->left,data);
    else
    if(data>root->data)
    	root->right=delete_node_BST(root->right,data);
    else
    {//data found
    	//if the node which we want to delete contain both left and right child.
    	//Then replace the key of this node with the largest value of its left subtree
    	//and recursively delete that node (now which is empty)
    	if(root->left&&root->right)
        {
        	temp=find_max(root->left);
        	root->data=temp->data;
        	root->left=delete_node_BST(root->left,root->data);
        }
        else//node which we want to delete have only one child
        	//eithe left or right
        {
            temp=root;
            if(root->left==NULL)
            	root=root->right;
            else
            if(root->right==NULL)
            	root=root->left;

            free(temp);
        }
    }

    return root;

}

int main(int argc, char const *argv[])
{
	int total,r;
	int delete_node;
	struct node *head=NULL;

	cout<<"enter total node: ";
	cin>>total;

	cout<<"\nenter range for node value: ";
	cin>>r;

	//call function to generate BST
    head=generate_BST(total,r);

    //call function to print the tree
    print_BST(head);

    cout<<"\nenter the node you want to delete:";
	cin>>delete_node;

    //function for deleting the node
    head=delete_node_BST(head,delete_node);

    //printing the tree after deleting the node
    print_BST(head);
    cout<<endl;
	
	return 0;
}