//program for finding the kth smallest element in BST

#include<iostream>
#include<stack>
#include "BST_utilities.h"

using namespace std;

//function for finding the kth smallest element in BST
int find_kth_smallest(struct node *root,int k)
{
	
    stack<struct node *> s;
    if(!root)
    	return 0;

    while(1)
    {
        while(root)
       {
    	    s.push(root);
    	    root=root->left;
       }
       
        if(s.empty())
         	 break;

        
        root=s.top();
        s.pop();
        k--;

        if(k==0)
        	return root->data;

        root=root->right;

        


    }

}

int main(int argc, char const *argv[])
{
	int total,r,result,k;
	struct node *head=NULL;

	cout<<"enter total node: ";
	cin>>total;

	cout<<"\nenter range for node value: ";
	cin>>r;

	//call function to generate BST
    head=generate_BST(total,r);

    //call function to print the tree
    print_BST(head);

    cout<<"\nenter the value of k: ";
    cin>>k;

    //call function for finding the kth smallest element
    result=find_kth_smallest(head,k);
    cout<<"\nkth smallest element is: "<<result<<endl;

	return 0;

}