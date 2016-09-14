//program to print total leave node in the tree

#include<iostream>
#include<queue>
#include "tree_utilities.h"

using namespace std;

int leave_node(struct node *root)
{
	//count will contain total leave node. Initialized with 0
    int count=0;
	queue<struct node *> q;
	struct node *temp;

    //initially push root node in the queue
	q.push(root);

    //loop until queue is not empty
	while(!q.empty())
	{
       temp=q.front();
       q.pop();
       if(!temp->left && !temp->right)
       	    count++;
       else
       {
            if(temp->left)
       	        q.push(temp->left);
            if(temp->right)
       	        q.push(temp->right);
       }

	}
	return count;
}

int main(int argc, char const *argv[])
{
   struct node *head;
   int total,r,max,count;

   //take input from user
   cout<<"enter total nodes:\n";
   cin>>total;

   //take input from user
   cout<<"enter range for node value:\n";
   cin>>r;

   //call function to buld the tree
   head=generate_tree(total,r);

   //print generated tree in preorder form
   cout<<"\ntree is:\n";
   print_tree1(head);

   //print the tree (inorder)
   cout<<"\ntree is:\n";
   print_tree2(head);

   //call function to find total leave node
   count=leave_node(head);

   cout<<"\ntotal leave nodes: \n"<<count<<endl;
	return 0;
}