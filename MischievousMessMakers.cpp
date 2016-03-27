//http://www.codeforces.com/problemset/problem/645/B
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	long long int ans = 0, valu, n, k;

	cin>>n>>k;
	
	valu = max(n-2*k, 0LL);

	ans  = n * (n - 1) / 2 - valu * (valu - 1) / 2;

	cout<<ans<<'\n';
	return 0;
}