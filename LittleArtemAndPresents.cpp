#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	long n, ans = 0;
	cin>>n;
	
	ans = (n / 3) * 2 + !!(n % 3);

	cout<<ans<<'\n';
	return 0;
}