//http://codeforces.com/contest/681/problem/B
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, a, b;
	bool ans = false;
	cin>>n;

	for (int i = 0; i * 1234567 <= n; ++i)
	{
		a = n - i * 1234567;
		
		for (int j = 0; j * 123456 <= a; ++j)
		{
			b = a - j * 123456;
		
			if( b % 1234 == 0)
				ans = true;
		}
	}
	if(ans)
		cout<<"YES"<<'\n';
	else
		cout<<"NO"<<'\n';
	return 0;
}