//Iterative tower of Hanoi

#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
int diskno,n;
stack<int>src, aux, dest;

void towofhan()
{
	
	for(int i=1;i<=diskno;i++)
	{
		if(i%3==1)
		{
			if(dest.empty())
			{
				dest.push(src.top());
				src.pop();
			}
			else
			if(src.empty()) 
			{
				src.push(dest.top());
				dest.pop();
			}
			else
			if( src.top()<dest.top())
			{
				dest.push(src.top());
				src.pop();
			}
			else
			{
				src.push(dest.top());
				dest.pop();	
			}
		}
		if(i%3==2)
		{
			if(aux.empty())
			{
				aux.push(src.top());
				src.pop();
			}
			else
			if(src.empty()) 
			{
				src.push(aux.top());
				aux.pop();
			}
			else
			if(src.top() < aux.top())
			{
				aux.push(src.top());
				src.pop();
			}
			else
			{
				src.push(aux.top());
				aux.pop();
			}
		}
		if(i%3==0)
		{
			
			if(dest.empty()) 
			{
				dest.push(aux.top());
				aux.pop();
			}
			else
			if( aux.empty()) 
			{
				aux.push(dest.top());
				dest.pop();
			}
			else
			if(aux.top() < dest.top())
			{
				dest.push(aux.top());
				aux.pop();
			}
			else
			{
				aux.push(dest.top());
				dest.pop();
			}
		}
	//cout<<src.size()<<" "<<aux.size()<<" "<<dest.size()<<"\n";
	}
}
int main() {
	//cin>>n;
	n=3;
	for(int i=n;i>=1;i--)
	src.push(i);
	diskno=(pow(2,n)-1);
	towofhan();
	cout<<dest.size()<<"\n";
	for(int i=1;i<=n;i++)
	{
		cout<<dest.top()<<" ";
		dest.pop();
	}
	return 0;
}