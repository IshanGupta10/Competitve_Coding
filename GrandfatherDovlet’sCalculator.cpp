//http://codeforces.com/contest/620/problem/B
#include <iostream>
using namespace std;

const int arr[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	long ans = 0;
	cin>>a>>b;
	for(int i = a; i <= b; ++i)
	{
		int x = i;
		while(x > 0)
		{
			ans += arr[x%10];
			x /= 10;
		}
	}
	cout<<ans<<'\n';
	return 0;
}