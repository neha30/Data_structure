//Program for searching element in the binary tree. This program contain both recursive and on recursive function for performing this operation.

#include<iostream>
#include<queue>
#include "tree_utilities.h"

using namespace std;

//recursive function to search element in BT
int search_recursive(struct node *root,int search)
{
	int temp;
    if(!root)
    	return 0;
    else
    {
        if(root->data==search)
            	return 1;
        else
        //recurse down to find the correct subtree
        {  
                temp=search_recursive(root->left,search);
                if(temp)
                	return 1;
                else
                	return search_recursive(root->right,search);
        }

    }
    if(root->data==search)
    	return 1;
    search_recursive(root->left,search);
    search_recursive(root->right,search);

}

//non recursive function to search the element in BT
void search_NonRecursive(struct node *root,int search)
{
    queue<struct node *> q;
    struct node *temp;

    //initially push root node in the queue
    q.push(root);

    while(!q.empty())
    {
    	temp=q.front();
    	q.pop();
    	if(temp->data==search)
        {
        	cout<<"\telement is present in tree\n";
        	return;
        }
        if(temp->left)
        	q.push(temp->left);
        if(temp->right)
        	q.push(temp->right);
    }
    cout<<"\telement not present in tree\n";
}

int main()
{
	struct node *head=NULL;
    int total,r,search,val;

    cout<<"enter total number of nodes in tree:\n";
    cin>>total;

    cout<<"\nenter the range for value of nodes:\n";
    cin>>r;

    //call function to build the binary tree
    head=generate_tree(total,r);

    //call function to print tree in preorder form
    cout<<"\ntree is:\n";
    print_tree1(head);

   //print the tree (inorder)
   cout<<"\ntree is:\n";
   print_tree2(head);

    cout<<"\nenter the element you want to search:\n";
    cin>>search;

    //call recursive function to search the element
    cout<<"\nusing recursive function:\n";
    val=search_recursive(head,search);
    if(val)
    	cout<<"\telement is present\n";
    else
    	cout<<"\telement is not present\n";

    //call non recursive function to search the tree
    cout<<"\nusing non recursive function:\n";
    search_NonRecursive(head,search);

	return 0;
}
