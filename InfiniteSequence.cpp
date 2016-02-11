//http://codeforces.com/contest/622/problem/0
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n, k = 1, i = 1;
	cin>>n;
	while(k <= n)
	{
		k += i;
		i++;
	}
	cout<<n - (k-i) <<'\n';
	return 0;
}