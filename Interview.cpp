//http://codeforces.com/contest/631/problem/A
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, x, a = 0, b = 0;
	cin>>n;
	
	for (int i = 0; i < n; ++i)
	{
		cin>>x;
		a |= x;
	}
	
	for (int i = 0; i < n; ++i)
	{
		cin>>x;
		b |= x;
	}

	cout<<a + b<<'\n';
	return 0;
}