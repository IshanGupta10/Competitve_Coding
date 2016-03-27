//http://www.codeforces.com/contest/652/problem/B
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> v, x;
	int n, t;

	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	for (int i = 0, j = n - 1; i < n/2, j >= n/2; ++i, --j)
	{
		x.push_back(v[i]);
		x.push_back(v[j]);
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<x[i]<<" ";
	}
	cout<<'\n';
	return 0;
}