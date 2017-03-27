#include<iostream>
#include<stack>

using namespace std;

void InsertBottom(stack<int> &s,int x)
{
	if(s.empty())
		s.push(x);
				
	else
	{
		int y=s.top();
		s.pop();
		InsertBottom(s,x);
		s.push(y);
	}
}

void Recursive(stack<int> &s)
{
	if(!s.empty())
	{
		int x=s.top();
		s.pop();
		Recursive(s);
		InsertBottom(s,x);
	} 
}

int main(int argc, char const *argv[])
{
	stack<int> s;
	int n,val;

	cout<<"total element in stack:";
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>val;
		s.push(val);
	}

	//print the stack
	cout<<"element of stack are:\n";
	for(stack<int> dump=s;!dump.empty();dump.pop())
		cout<<dump.top()<<"\n";

	//call function to reverse the stack
	Recursive(s);

	cout<<"element of stack after reversal are:\n";
	for(stack<int> dump=s;!dump.empty();dump.pop())
		cout<<dump.top()<<"\n";	

	return 0;
}