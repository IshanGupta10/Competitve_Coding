//http://codeforces.com/contest/617/problem/A
#include <iostream>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, ans = 0;
	cin>>n;
	if(n <= 5)
	{
		cout<<1<<'\n';
	}
	else
	{
		while(n > 5)
		{
			n -= 5;
			ans++;
		}
		cout<<++ans<<'\n';
	}
	return 0;
}