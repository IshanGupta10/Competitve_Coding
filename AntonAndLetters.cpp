//http://codeforces.com/problemset/problem/443/A
#include <iostream>
#include <set>
using namespace std;

int main() 
{
	
	set<char> st;
	char ch;
	while(ch != '}')
	{
		cin>>ch;
		if(ch >=97 && ch <=122)
			st.insert(ch);
		else
			continue;
	}
	cout<<st.size()<<'\n';
	return 0;
}