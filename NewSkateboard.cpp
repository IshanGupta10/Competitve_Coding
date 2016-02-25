//http://codeforces.com/contest/628/problem/B
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	ulli ans = 0, prev = 0;
	cin>>s;

	for (int i = 0; i < s.size(); ++i)
	{
		int v = s[i] - '0';
		
		if((v & 3) == 0)
			ans++;
		
		if(((prev * 10 + v) & 3) == 0)
			ans += i;
		prev = v;
	}
	cout<<ans<<'\n';
	return 0;
}