//procedure -
//1. Calculate the total number of moves required i.e. "pow(2, n)
//   - 1" here n is number of disks.
//2. If number of disks (i.e. n) is even then interchange destination 
//   pole and auxiliary pole.
//3. for i = 1 to total number of moves:
//     if i%3 == 1:
//	legal movement of top disk between source pole and 
//       destination pole
//     if i%3 == 2:
//	legal movement top disk between source pole and 
//        auxiliary pole	
//     if i%3 == 0:
//        legal movement top disk between auxiliary pole 
//        and destination pole 



#include<iostream>
#include<math.h>
#include<stack>
using namespace std;

void move_back(stack<int> &s1,stack<int> &s2)
{
	while(!s2.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}

}

//function for printing the content of all the stack after one move
void print_movedisk(stack<int> &src,stack<int> &aux,stack<int> &dest)
{
	stack<int> temp;

	cout<<"\nsource rod:";
	if(!src.empty())
	{
		while(!src.empty())
		{
			cout<<src.top()<<"---->";
			temp.push(src.top());
			src.pop();
		}	
		move_back(src,temp);
	}
	else
		cout<<"---";

	cout<<"\nauxillary rod:";
	if(!aux.empty())
	{
		while(!aux.empty())
		{
			cout<<aux.top()<<"---->";
			temp.push(aux.top());
			aux.pop();
		}	
		move_back(aux,temp);
	}
	else
		cout<<"----";

	cout<<"\ndestination rod:";
	if(!dest.empty())
	{
		while(!dest.empty())
		{
			cout<<dest.top()<<"---->";
			temp.push(dest.top());
			dest.pop();
		}	
		move_back(dest,temp);
	}
	else
		cout<<"----";

	cout<<"\n";
}

void move_between_disk(stack<int> &s1,stack<int> &s2)
{
	//if one of the stak is empty then push the top element of other stack
	//int epty stack and pop it from that stack
	if(s1.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}

	else if(s2.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}
	else if(s1.top()>s2.top())    //when top of one stack is greater then the top of other stack 
	{
		s1.push(s2.top());
		s2.pop();
	}
	else if(s1.top()<s2.top())
	{
		s2.push(s1.top());
		s1.pop();
	}

}

void tower_of_hanoi(int n)
{
	int no_of_moves;
	stack<int> src;			//source rod
	stack<int> aux;			//auxillary rod
	stack<int> dest;		//destination rod

	//push disk into source rod
	for(int i=n;i>=1;i--)
		src.push(i);

	no_of_moves=pow(2,n)-1;

	for(int i=1;i<=no_of_moves;i++)
	{
		if(i%3==1)
		{
			move_between_disk(src,dest);
			print_movedisk(src,aux,dest);
		}
		else if(i%3==2)
		{
			move_between_disk(src,aux);
			print_movedisk(src,aux,dest);
		}
		else if(i%3==0)
		{
			move_between_disk(aux,dest);
			print_movedisk(src,aux,dest);
		}

	}
}


int main(int argc, char const *argv[])
{
	int n;

	cout<<"enter total no. of disk:";
	cin>>n;

	tower_of_hanoi(n);
	return 0;
}