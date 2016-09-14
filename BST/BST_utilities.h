#ifndef BST_UTILITIES_h
#define BST_UTILITIES_h

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

//function to generate BST
struct node *generate_BST(int total,int r);

//function to print BST (preorder tarversal)
void print_BST(struct node *root);

//function for searching key in BST
struct node *search(struct node *root,int key);


#endif

