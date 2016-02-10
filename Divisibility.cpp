//http://codeforces.com/problemset/problem/597/A
#include <iostream>
using namespace std;

typedef long long int lli;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	lli e, s, d;
	cin>>d>>s>>e;
	e = e <  0 ? (e+1)/d - 1 : e/d;
	s = s <= 0 ? s/d - 1 : (s-1)/d;
	cout<<e-s<<'\n';
	return 0;
}
