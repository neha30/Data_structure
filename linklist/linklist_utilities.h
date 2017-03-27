#ifndef LINKLIST_UTILITIES_H
#define LINKLIST_UTILITIES_H

struct node
{
	int data;
	struct node *next;
};

//function to generate linkllist
struct node *insert_node(int,struct node *);

//print linklist element
void print_linklist(struct node *);

//delete node from linklist
struct node *delete_node(int, struct node *);

#endif