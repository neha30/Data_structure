#include<iostream>
#include<queue>
#include "tree_utilities.h"

using namespace std;


//recursive function to find the size of tree
int size_recursive(struct node *root)
{
    if(!root)
    	return 0;
    else
    	return 1+size_recursive(root->left)+size_recursive(root->right);
}

//non recursive function to find the size of tree
void size_NonRecursive(struct node *root)
{
   int count=0; 
   queue<struct node *> q;
   struct node *temp;

   //initially push root node in queue
   q.push(root);
   while(!q.empty())
   {
       temp=q.front();
       q.pop();
       count++;
       if(temp->left)
       	  q.push(temp->left);
       if(temp->right)
       	  q.push(temp->right);

   }
   cout<<"\ntree size using non recursive function: "<<count<<endl;

}

int main(int argc, char const *argv[])
{

	struct node *head=NULL;
    int total,r,size;
 
    cout<<"enter total number of nodes:\n";
    cin>>total;
 
    cout<<"enter range for node value:\n";
    cin>>r;

    //call function to build the tree
    head=generate_tree(total,r);

    //call function to print the tree
    cout<<"\ntree is:\n";
    print_tree1(head);

    //print the tree (inorder)
    cout<<"\ntree is:\n";
    print_tree2(head);

    //call recursive function to find the size of tree
    size=size_recursive(head);
    cout<<"\ntree size using recursive function: "<<size<<endl;

    //call non recursive function to find the size of tree
    size_NonRecursive(head);

	
    return 0;
}
