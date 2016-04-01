//http://www.codeforces.com/contest/638/problem/B
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	string k, s = "";
	cin>>n;

	if(n == 1)
	{
		cin>>k;
		s += k;
	}
	else
	{
		while(n--)
		{
			cin>>k;
			s += k;
		}

		sort(s.begin(),s.end());

		s.erase(unique(s.begin(), s.end()),s.end());
	}
	cout<<s<<'\n';

	return 0;
}