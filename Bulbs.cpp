//http://codeforces.com/contest/615/problem/A
#include <iostream>
#include <map>
using namespace std;


int main()
{
	map<int,bool> mp;
	int n, m, t, x;
	cin>>n>>m;
	for(int i=1; i<= m; i++)
	{
		if(mp.find(i)!=mp.end())
			continue;
		else
			mp[i] = false;
	}

	for(int i=0 ; i< n; i++)
	{
		cin>>t;
		while(t--)
		{
			cin>>x;
			if(mp.find(x) != mp.end())
				mp[x] = true;
		}
	}
	
	for(int i=1; i<= m; i++)
	{
		if(mp[i])
			continue;
		else
		{
			t = false;
			break;
		}
	}
	if(t)
		cout<<"YES"<<'\n';
	else
		cout<<"NO"<<'\n';
	return 0;
}