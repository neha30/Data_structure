//program for prinitng nodes on vetical line

#include<iostream>
#include "tree_utilities.h"

using namespace std;

//function for finding the maximum and minimum distance from root to all node
void find_max_min(struct node *root,int *max,int *min,int hd)
{
	//base case
    if(!root)
    	return;

    if(hd<*min)
    	 *min=hd;
    else
    if(hd>*max)
    	 *max=hd;

    find_max_min(root->left,max,min,hd-1);
    find_max_min(root->right,max,min,hd+1);

}

void print_node(struct node *root,int val,int hd)
{
	//base case
	if(root==NULL)
		return;

	//if this node is on the given line number
	if(hd==val)
		cout<<root->data<<" ";
		
	
	
	//otherwise call function recur
	print_node(root->left,val,hd-1);
	print_node(root->right,val,hd+1);
}

//function for finding the vertical line
void vertical_line_BT(struct node *root)
{
   int max=0,min=0,hd,i;

   //call function to find max and min distance from root node, here last argument is passed 0
   //which shows that root node is at distance 0
   find_max_min(root,&max,&min,0);
   

   //cout<<"max min value is:"<<max<<min<<endl;
   
   //loop through all the values from min to max print the node of tree of particular value
   cout<<"nodes on lines:\n";
   for(i=min;i<=max;i++)
   {
   	   print_node(root,i,0);
   	   cout<<endl;
   }

}

int main(int argc, char const *argv[])
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

    vertical_line_BT(head);
	return 0;
}
