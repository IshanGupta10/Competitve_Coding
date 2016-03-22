//http://www.codeforces.com/problemset/problem/637/A
#include <bits/stdc++.h>
using namespace std;
 
int main(int args, char *argv[]) 
{
	map<int,int> mp;
	int n, x, max = 0, val;
	cin>>n;
 
	for(int i = 0; i < n; ++i)
	{
		cin>>x;
		if(mp.find(x) != mp.end())
			mp[x]++;
		else
			mp[x] = 1;
	}
 
	for(auto i:mp)
	{
		if(i.second >= max)
		{
			max = i.second;
			val = i.first;
			cout<<max<<" "<<val<<'\n';
		}
	}
 
	cout<<val<<'\n';
 
	return 0;
}