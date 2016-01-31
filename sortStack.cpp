// http://www.geeksforgeeks.org/sort-a-stack-using-recursion/

#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int> &st,int aux)
{
	if(st.empty() || aux > st.top())
	{
		st.push(aux);
		return;
	}
	int temp = st.top();
	st.pop();
	sortedInsert(st,aux);
	st.push(temp);
}

void sortStack(stack<int> &st)
{
	if(!st.empty())
	{
		int temp = st.top();
		st.pop();
		sortStack(st);
		sortedInsert(st, temp);
	}
}

int main() 
{
	stack<int> st;
	st.push(5);
	st.push(4);
	st.push(3);
	st.push(2);
	st.push(1);
	cout<<st.size()<<" <-- Size "<<endl;
	while(!st.empty())
	{
		cout<<st.top();
		cout<<endl;
		st.pop();
	}
	st.push(5);
	st.push(4);
	st.push(3);
	st.push(2);
	st.push(1);
	sortStack(st);
	cout<<"Here"<<endl;
	while(!st.empty())
	{
		cout<<st.top();
		st.pop();
		if(!st.empty())
			cout<<endl;
	}
	return 0;
}
