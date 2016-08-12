//http://codeforces.com/problemset/problem/706/B
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, t, q, val;
	vector<int> v;
	
	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	cin>>q;

	while(q--)
	{
		cin>>val;
		vector<int>::iterator up = upper_bound(v.begin(), v.end(), val);
		cout<<(up - v.begin())<<'\n';
	}
	return 0;
}
