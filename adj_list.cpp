//c program for adjacency list representation

#include<iostream>
#include<stdlib.h>

using namespace std;

struct AdjListNode
{
	int dest;
	struct AdjListNode *next;
};

struct AdjList
{
	struct AdjListNode *head;
};

struct Graph
{
	int v;
	struct AdjList *array;
};


struct AdjListNode *newAdjListNode(int dest)
{
	struct AdjListNode *newnode=(struct AdjListNode *)malloc(sizeof(struct AdjListNode));
	newnode->dest=dest;
	newnode->next=NULL;

	return newnode;
}

struct graph *create_graph(int v)
{
    int i;
    struct graph *graph=(struct graph *)malloc(sizeof(struct graph));
    graph->v=v;
    graph->array=(struct AdjList *)malloc(sizeof(AdjList)*v);

    for(i=0;i<v;i++)
    {
        graph->array[i].head=NULL;
    }
    return graph;
}


void AddEdge(struct graph *graph,int src,int dest)
{
    struct AdjListNode *newnode=newAdjListNode(dest);
    newnode->next=graph->array[src].head;
    grah->array[src].head=newnode;

    //since graph is undirected, add and edge from dest to src also
    newnode=newAdjListNode(src);
    newnode->next=graph->array[dest].head;
    graph->array[dest].head=newnode;
}

void PrintGraph(struct graph *graph)
{
    int v;
    for(v=0;v<graph->v;++v)
    {
    	struct AdjListNode *crawl=graph->array[v].head;
    	cout<<"print adjacency list of vertex "<<v;

    	while(crawl)
    	{
    		cout<<"--->"<<crawl->dest;
    		crawl=crawl->next;
    	}
    	cout<<endl;
    }
}



int main(int argc, char const *argv[])
{
	int total,i;
	int src,dest;
    struct graph *graph=NULL;
	cout<<"total number of nodes:";
	cin>>total;

    graph=create_graph(total);

    for(i=0;i<total;i++)
    {
         cout<<"enter source:";
         cin>>src;
         cout<<"\nenter destination:";
         cin>>dest;
         AddEdge(graph,src,dest);
    }

    //print the graph
    PrintGraph(graph);
	return 0;
}