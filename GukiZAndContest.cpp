//http://www.codeforces.com/problemset/problem/551/A
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	map<int,int> mp;
	vector<int> v, x;
	int n, t;
	cin>>n;
	
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		v.push_back(t);
		x.push_back(t);
	}
	
	sort(x.begin(), x.end(), greater<int>());
	
	for (int i = 1; i <= n; ++i)
	{
		if(mp.find(x[i-1]) != mp.end())
			continue;
		else
			mp[x[i-1]] = i;
	}
	
	// for(auto i = mp.begin(); i != mp.end(); ++i)
	// 	cout<<i->first<<" "<<i->second<<'\n';
	
	for(int i = 0; i < n; ++i)
		if(mp.find(v[i]) != mp.end())
			cout<<mp[v[i]]<<" ";

	return 0;
}