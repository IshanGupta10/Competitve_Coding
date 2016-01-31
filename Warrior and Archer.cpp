#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	
	if(n == 2)
		cout<<abs(a[0]-a[1]);
	else
	{
		sort(a,a+n);
		int x = n/2;
		int ans = 1000000007;

		for (int i = 0; i+x < n; ++i)
			ans = min(ans,a[i+x]-a[i]);

		cout<<ans;
	}
	return 0;
}