#include<iostream>
#include<stack>
#include<string>

using namespace std;


void postfixEval(string exp)
{
	stack<int> myStack;

	for(int i=0;i<exp.length();i++)
	{
		//if current input is number push it into stack
		if(isdigit(exp[i]))
			myStack.push(exp[i]-'0');
		else
		{
			//current input i operator then pop two values from the stack perfrom the operation and push back the result in stack
			int val1=myStack.top();
			myStack.pop();
			int val2=myStack.top();
			myStack.pop();

			switch(exp[i])
			{
				case '+':myStack.push(val2+val1); 
						 break;
				case '-':myStack.push(val2-val1);
						 break;
				case '*': myStack.push(val2*val1);
				         break;
				case '/': myStack.push(val2/val1);

			}
		}

	}

	cout<<"result is: "<<myStack.top()<<"\n";
}



int main(int argc, char const *argv[])
{
	string exp;
	cout<<"enter postfix expression:";
	cin>>exp;

	//call function for postfix evaluation
	postfixEval(exp);
	
	return 0;
}