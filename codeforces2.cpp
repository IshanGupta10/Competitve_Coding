#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	char p,q,x;
	string k;
	cin>>k;
	multimap<char,char> mp;
	for (int i = 0; i < n; ++i)
	{
		mp.insert(make_pair(k[i],k[i]));
	}
	while(m--)
	{
		cin>>p>>q;
		while(mp.find(p)!=mp.end())
		{
			mp.insert(make_pair(p,q));
		}
		while(mp.find(q)!=mp.end())
		{
			mp.insert(make_pair(q,p));
		}
	}
	for (multimap<char,char>::iterator i = mp.begin(); i != mp.end(); ++i)
	{
		cout<<(*i).second;
	}
	return 0;
}