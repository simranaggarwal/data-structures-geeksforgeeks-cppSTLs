//Infix to postfix

#include <iostream>
#include <stack>
#include <string>
using namespace std;
int prec(char ch)
{
	switch(ch)
	{
		case '/' :
		case '*' : return 3;
		case '+' :
		case '-' : return 2;
		default: break;
	}
	return 0;
}
string inftopf(string inf)
{	
	string pf;
	stack <char> s;
	int weight;
	int i=0,k=0;
	char ch;
	while(inf[i]!='\0')
	{
		ch=inf[i];
		if(ch=='(')
		{
			s.push(ch);
			i++;
			continue;
		}
		if(ch==')')
		{
			while(!s.empty() && s.top()!='(')
			{
				pf.push_back(s.top());
				s.pop();
			}
			if(!s.empty())
			{
				s.pop();
			}
			i++;
			continue;
		}
		weight=prec(ch);
		if(weight==0)
		{
			 pf.push_back(ch);
			 //s.pop();
		}
		else
		{
			while(!s.empty() && s.top()!='(' && prec(ch)<=prec(s.top()))
			{
				pf.push_back(s.top());
				s.pop();
			}
			s.push(ch);
		}
		i++;
	}
	while(!s.empty())
	{
		pf.push_back(s.top());
		s.pop();
	}
	return pf;
}
int main() {
	string inf="a*(b+c)+d";
	string pf;
	pf=inftopf(inf);
	cout<<pf;//<<endl;
	return 0;
}