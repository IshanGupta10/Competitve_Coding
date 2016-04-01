//http://www.codeforces.com/contest/659/problem/B
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	int n, m, x, p, q;
	cin>>n>>m;
	vector<pair<int,string> > v[m];
	vector<string> str;
	
	for (int i = 0; i < n; ++i)
	{
		cin>>s>>p>>q;
		p--;
		v[p].push_back(make_pair(q,s));
	}

	for (int i = 0; i < m; ++i)
		sort(v[i].rbegin(),v[i].rend());


	for (int i = 0; i < m; ++i)
	{
		if(v[i][0].first == v[i][1].first)
			cout<<"?"<<'\n';
		else
			cout<<(v[i][0].second)<<" "<<v[i][1].second<<'\n';
	}

	return 0;
}