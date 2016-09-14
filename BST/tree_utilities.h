#ifndef TREE_UTILITIES_H
#define TREE_UTILITIES_H

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

//function to generate tree
struct node *generate_tree(int total,int r);

//function to print tree
void print_tree1(struct node *root);

//function to print tree(inorder)
void print_tree2(struct node *root);

#endif


