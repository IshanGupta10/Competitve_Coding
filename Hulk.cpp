//http://codeforces.com/contest/705/problem/A
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s = "I hate ";
	int n;

	cin>>n;

	if(n == 1)
	{
		cout<<"I hate it"<<'\n';
		return 0;
	}
	else
	{
		for (int i = 2; i <= n; ++i)
		{
			if(i % 2)
				s += "that I hate ";
			else
				s += "that I love ";
		}

		s += "it";
	}
	cout<<s<<'\n';
	return 0;
}