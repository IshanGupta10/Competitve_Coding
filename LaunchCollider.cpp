///http://codeforces.com/contest/699/problem/A
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	vector<int> v;
	int n, ans = INT_MAX, t;
	string s;
	
	cin>>n;
	cin>>s;
	
	for(int i = 0; i  < n; ++i)
	{
		cin>>t;
		v.push_back(t);
		if(i == 0)
			continue;
		if(s[i] == 'L' && s[i - 1] == 'R')
			ans = min(ans, (v[i] - v[i - 1]) / 2);
	}
	if(ans == INT_MAX)
		cout<<-1<<'\n';
	else
		cout<<ans<<'\n';		
	return 0;
}