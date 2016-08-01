//Write a C program that, given an array A[] of n numbers and another number x, determines whether or not there exist two elements 
//in S whose sum is exactly x. 
//Let x be the given sum and MyVec[] be the array in which we need to find pair.

//1) create the hasmap MyMap
//2) Do following for each element MyVec[i] in MyVec[]
//   (a)	If MyMap[x - MyVec[i]] is set then print the pair (MyVec[i], x - MyVec[i])
//   (b)	Set MyMap[MyVec[i]]


#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main(int argc, char const *argv[])
{
	
	vector<int> MyVec;   //vector of integer
	map<int,int> MyMap;		//creating map
	int total,val,x;

	cout<<"enter total element:";
	cin>>total;

	for(int i=0;i<total;i++)
		{
			cin>>val;
			MyVec.push_back(val);
		}

	//vector<int>::iterator it;
	//sort(MyVec.begin(),MyVec.end());	

	cout<<"\nenter the value of x:";
	cin>>x;
	
	map<int,int>::iterator it;

	for(int i=0;i<total;i++)
	{
		int temp=x - MyVec[i];
		it=MyMap.find(temp);
		if(it!=MyMap.end())
		{
			cout<<"\npirs is : "<<temp<<" "<<MyVec[i]<<endl;
			break;
		}
		MyMap[MyVec[i]]=1;	

	}
	return 0;
	
}