//Program for infix to postfix conversion

#include<iostream>
#include<stack>
#include<string>

using namespace std;

int Precedence(char op)
{
	switch(op)
	{
		case '+':
		case '-': return 1;

		case '*':
		case '/': return 2;

		case '^': return 3;

	}
	return -1;
}


void InfixToPostfix(string str)
{
	stack<char> myStack;
	int k=-1;
	//char *output=new char[str.length()];
	//int index=-1;

	for(int i=0;i<str.length();i++)
	{
		//if current input is alphabet
		if(isalpha(str[i]))			
			str[++k]=str[i];
		
		else
		{
			//if current i/p is opening bracket then push it into stack 
			if(str[i]=='(')
				myStack.push(str[i]);

			else if(str[i]==')')
			{
				while(myStack.top()!='(')
				{					
					str[++k]=myStack.top();
					myStack.pop();
				}
				myStack.pop();
			}
			//if stack is empty and current input is an operator push the operator in stack
			else 
			{
				//check for the precedence
				while(!myStack.empty() && (Precedence(str[i])<=Precedence(myStack.top())))
				{
					str[++k]=myStack.top();
					myStack.pop();
				}
				myStack.push(str[i]);
			}		

		}
	}
	while(!myStack.empty())
	{
		str[++k]=myStack.top();
		myStack.pop();
	}

	cout<<"\nPostfix expression is: "<<str;
	//for(int i=0;i<str.length();i++)
	//	cout<<output[i];

	cout<<"\n";
}



int main(int argc, char const *argv[])
{	
	string str;

	cout<<"enter infix expression:";
	cin>>str;

	//call function to convert into postfix form
	InfixToPostfix(str);
	return 0;
}