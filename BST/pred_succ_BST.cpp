//program for finding the inroder predecessor and successor of given key in BST

#include<iostream>
#include "BST_utilities.h"

using namespace std;

//function for finding maximum element in BST
struct node *find_max(struct node *root)
{
	if(!root)
		 return NULL;
	if(!root->right)
		 return root;

	return find_max(root->right);
}

//function for finding minimum element in BST
struct node *find_min(struct node *root)
{
    if(!root)
		return NULL;
	if(!root->left)
		return root;

	return find_min(root->left);
}

void pred_succ_BST(struct node *root,int key)
{
	struct node *temp,*pred,*succ;
	//base case
	if(!root)
		return;
	else
    {//search the key into BST
    	temp=search(root,key);
         
         //inorder predecessor is max element in left subtree of key node
        pred=find_max(root->left);
        succ=find_min(root->right);

        cout<<"\npredecessor and successor of key is ";

        if(pred!=NULL)
        	cout<<pred->data<<"\n";
        else
        	cout<<"NULL\n";

        if(succ!=NULL)
        	cout<<succ->data<<"\n";
        else
        	cout<<"NULL\n";

    }
}


int main(int argc, char const *argv[])
{
	int total,r,key;
	struct node *head=NULL;

	cout<<"enter total node: ";
	cin>>total;

	cout<<"\nenter range for node value: ";
	cin>>r;

	//call function to generate BST
    head=generate_BST(total,r);

    //call function to print the tree
    print_BST(head);

    cout<<"\nenter the key whose predecessor and successor you want to know: ";
    cin>>key;

    //call function for finding the inorder predecessor and successor
     pred_succ_BST(head,key);

	return 0;
}