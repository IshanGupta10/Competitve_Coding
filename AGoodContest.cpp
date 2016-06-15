//http://codeforces.com/contest/681/problem/A
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	map<string, pair<int, int>> mp;
	int n, a, b;
	string s;
	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		cin>>s>>a>>b;
		mp[s] = make_pair(a,b);
	}

	for(auto i = mp.begin(); i != mp.end(); ++i)
	{
		if(i->second.first >= 2400 && i->second.second - i->second.first > 0)
		{
			cout<<"YES"<<'\n';
			return 0;
		}
	}
	cout<<"NO"<<'\n';
	return 0;
}