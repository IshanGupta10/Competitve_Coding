//http://codeforces.com/contest/609/problem/A
#include <iostream>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<int, int> mp;
	int n,m,count = 0, sum = 0;
	cin>>n>>m;
	int a[n];
	
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	
	sort(a,a+n,greater<int>());
	
	for (int i = 0; i < n; ++i)
		if(mp.find(a[i]) != mp.end())
			mp[a[i]]++;
		else
			mp[a[i]] = 1;
	
	if(mp.find(m) != mp.end())
		cout<<1<<'\n';
	else
	{
		for (int i = 0; i < n; ++i)
		{
			sum += a[i];
			count++;
			if(sum == m)
				break;
			if(sum > m)
				break;
		}
	cout<<count<<'\n';
	}
	return 0;
}