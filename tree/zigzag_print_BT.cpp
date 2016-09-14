//program to print tree in zigzag form
//for ex      1           
//           /  \       -----> o/p 1 3 2 4 5 6 7
//          2    3
//         / \   /\
//        4   5  6 7

#include<iostream>
#include "tree_utilities.h"

using namespace std;

//recur function for finding the height of binary tree
int height_BT(struct node *root)
{
	int lh,rh;
	if(!root)
		return 0;
	else
	{
		lh=height_BT(root->left);
		rh=height_BT(root->right);
		if(lh>rh)
			return lh+1;
		else
			return rh+1;
	}
}

//function for printing levels
int level_print(struct node *root,int level,int lefttoright)
{
	//base case
	if(!root)
		return 0;
	//if reach at the current level
	if(level==1)
		cout<<root->data<<" ";
	if(level>1)
	{
		if(lefttoright)
		{
			//push from left to right
			level_print(root->left,level-1,lefttoright);
			level_print(root->right,level-1,lefttoright);
		}
		else
		{
			//push from right to left
			level_print(root->right,level-1,lefttoright);
			level_print(root->left,level-1,lefttoright);
		}
	}
}

//function fro printing tree in zigzag form
void zigzag_print(struct node *root)
{
	int height;
	int lefttoright=0;

    //find the height of tree
	height=height_BT(root);

    //loop for printing level by level
	for(int i=1;i<=height;i++)
	{
            level_print(root,i,lefttoright);
            lefttoright=!lefttoright;
	}
}

int main()
{

	struct node *head;
    int total,r,result;

    //take input from user
    cout<<"enter total nodes:\n";
    cin>>total;

    //take input from user
    cout<<"enter range for node value:\n";
    cin>>r;

    //call function to buld the tree
    head=generate_tree(total,r);

    //print generated tree in preorder form
    cout<<"\n preorder traversal of tree is:\n";
    print_tree1(head);

    //print the tree (inorder)
    cout<<"\ninorder traversal of tree is:\n";
    print_tree2(head);

    //call function to print tree in zigzag form
    zigzag_print(head);
    cout<<endl;
}