#include<iostream>
#include<stack>
#include<string>
using namespace std;

void LongestSubstringLength(string exp)
{
	stack<int> s;
	int result=0;	//initialize result to zero

	//push -1 in stack. The first element of stack is used to provide base for next valid string
	s.push(-1);

    for(int i=0;i<exp.length();i++)
    {
    	//if current i/p is '(' then push its index into stack
    	if(exp[i]=='(')
    		s.push(i);
    	else
    	{
    		//pop element from stack
    		s.pop();

    		//take the difference of top element of stack and current index if it is greater than result then update result
    		if(!s.empty())
    		{
    			int diff=i-s.top();
    			if(diff>result)
    				result=diff;
    		}
    		else
    			s.push(i);
    	}
    }

    cout<<"\nlength of longest substring is: "<<result<<"\n";

}

int main(int argc, char const *argv[])
{
	string exp;

	cout<<"enter expression:";
	cin>>exp;

	LongestSubstringLength(exp);
	return 0;
}