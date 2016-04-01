//http://www.codeforces.com/contest/659/problem/A
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, a, b, ans = 0;
	cin>>n>>a>>b;

	if(b >= 0)
	{
		if(b >= n)
		{
			ans = b % n;
			ans += a;
		}
		else
			ans = a + b;
		if(ans > n)
			ans %= n;
	}
	else if(n == -b)
	{
		ans = a;
	}
	else
	{
		if(b == -1)
		{
			a += b;
			if(a == 0)
				ans = n;
			else
				ans = a;
		}
		else
		{
			int k = 0;
			while(k != b)
			{
				a--;
				k--;
				if(a == 0)
					a = n;
			}
			if(a < 0)
				ans = -a;
			else
				ans = a;
		}
	}

	cout<<ans<<'\n';
	return 0;
}