//que: http://www.geeksforgeeks.org/next-greater-element/

#include<iostream>
#include<stack>

using namespace std;

void NextGreaterElement(int n,int *arr)
{
	stack<int> s;

	//push first element into stack
	s.push(arr[0]);

	for(int i=1;i<n;i++)
	{
			if(arr[i]<=s.top()) //push curr element into stack
				s.push(arr[i]);
			else
			{
				while(!s.empty() && arr[i]>s.top());
				{
					cout<<s.top()<<"--->"<<arr[i]<<"\n";
					s.pop();
				}
				s.push(arr[i]);
			}
		
	
	}
	while(!s.empty())
	{
		cout<<s.top()<<"--->-1\n";
		s.pop();
	}


}

int main(int argc, char const *argv[])
{
	int n;
	int *arr;

	cout<<"total element in array:";
	cin>>n;

	arr=new int[n];

	//enter element
	cout<<"\nenter element:";
	for(int i=0;i<n;i++)
		cin>>arr[i];

	NextGreaterElement(n,arr);

	return 0;
}