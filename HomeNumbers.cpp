//http://www.codeforces.com/contest/638/problem/A
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, a, ans = 1;
	cin>>n>>a;

	if(a % 2)
	{
		int  k = 1;
		while(k != a)
		{
			k += 2;
			ans++;
		}
	}
	else
	{
		ans  += (n - a) / 2;
	}

	cout<<ans<<'\n';
	return 0;
}