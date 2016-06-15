//http://codeforces.com/contest/667/problem/B
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, t;
	vector<int> v;
	long ans = 0;
	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		v.push_back(t);
	}

	ans = *max_element(v.begin(), v.end()) - (accumulate(v.begin(), v.end(), 0) - *max_element(v.begin(), v.end())) + 1;

	cout<<ans<<'\n';
	return 0;
}