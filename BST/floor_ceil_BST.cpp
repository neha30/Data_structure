//Program for finding floor (ceil). This can be used in many application for ex. assigning the best fit memory
//for ex    8              
 //       /   \       -----> consider this BST node will represnt free memory wherenode value is the size of memory. Suppose some
 //      4     12          program will come whose size is 3 then we have to find the best fit for it. so here it must fit in node 
//      / \    /  \        value 4.
//      2  6  10  14

#include<iostream>
#include "BST_utilities.h"

using namespace std;

//function for finding the ceil value
int ceil(struct node *root,int key)
{
	int val;
	//base case
	if(!root)
		return -1;
 
    //when root data is equal to key means root is the best fit
    if(root->data==key)
    	return root->data;
    
    //search in right subtree
    if(root->data<key)
    	return ceil(root->right,key);
    
    //either left subtree or root have the key value
    val=ceil(root->left,key);
    return (val>=key)?val:root->data;

}

//main will start here
int main()
{
	int total_mem,total_prog,r,size_prog;
	struct node *head=NULL;

	cout<<"enter total memory: ";
	cin>>total_mem;

	cout<<"\nenter range for memory size: ";
	cin>>r;

	//call function to generate BST
    head=generate_BST(total_mem,r);

    //call function to print the tree
    print_BST(head);

    //take input from the user for finding the best fit 
    cout<<"\nenter total programs you want to store: ";
    cin>>total_prog;

    //take input from the user for programs size
    cout<<"\nenter the size of programs: \n";
    for(int i=1;i<=total_prog;i++)
    {
    	cin>>size_prog;
    	cout<<"\nprogram size: "<<size_prog<<"\t"<<"allocated memory: "<<ceil(head,size_prog)<<endl;
    }

    cout<<endl;
    return 0;
}
