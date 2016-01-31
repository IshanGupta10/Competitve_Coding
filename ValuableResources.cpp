//http://codeforces.com/contest/485/problem/B
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	ll x[n],y[n];
	
	for (ll i = 0; i < n; ++i)
		cin>>x[i]>>y[i];

	ll xside = *max_element(x,x+n) - *min_element(x,x+n);
	ll yside = *max_element(y,y+n) - *min_element(y,y+n);
	
	ll square = max(xside,yside);
	cout<<square*square<<'\n';
	return 0;
}