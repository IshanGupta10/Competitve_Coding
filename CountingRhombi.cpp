//http://www.codeforces.com/problemset/problem/189/B
#include <iostream>
using namespace std;

typedef unsigned long long int ulli;

int main() 
{
	ulli n, m, ans = 0;
	cin>>n>>m;

	for (int i = 2; i <= n; i += 2)
	{
		for (int j = 2; j <= m; j += 2)
		{
			ans += (n-i+1) * (m-j+1);
		}
	}

	cout<<ans<<'\n';
	return 0;
}