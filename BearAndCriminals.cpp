// http://codeforces.com/contest/680/problem/B
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> v;
	int n, a, t, ans = 0;

	cin>>n>>a;

	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		v.push_back(t);
	}

	a--;

	int l = a - 1, r = a + 1;

	if(v[a])
		ans++;

	while(l >= 0 && r < n)
	{
		if(v[l] && v[r])
			ans += 2;

		l--;
		r++;
	}

	while(l >= 0)
	{
		if(v[l])
			ans++;

		l--;
	}

	while(r < n)
	{
		if(v[r])
			ans++;
		r++;
	}
	cout<<ans<<'\n';
	return 0;
}