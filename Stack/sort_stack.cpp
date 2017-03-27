#include<iostream>
#include<stack>
using namespace std;

void InsertSorted(stack<int> &s,int x)
{
	if(s.empty() ||x>s.top())
		s.push(x);
	else
	{
		int y=s.top();
		s.pop();
		InsertSorted(s,x);
		s.push(y);
	}
}

void SortStack(stack<int> &s)
{
	if(!s.empty())
	{
		int x=s.top();
		s.pop();
		SortStack(s);
		InsertSorted(s,x);
	}
}

int main(int argc, char const *argv[])
{
	stack<int> s;
	int n,val;

	cout<<"total element in stack:";
	cin>>n;

	cout<<"enter element:\n";
	for(int i=0;i<n;i++)
	{
		cin>>val;
		s.push(val);
	}

	//print the stack
	cout<<"element of stack are:\n";
	for(stack<int> dump=s;!dump.empty();dump.pop())
		cout<<dump.top()<<"\n";

	SortStack(s);

	//print the stack
	cout<<"element of stack after sorting:\n";
	for(stack<int> dump=s;!dump.empty();dump.pop())
		cout<<dump.top()<<"\n";	
	return 0;
}