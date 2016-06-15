// http://codeforces.com/contest/678/problem/C
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;

ulli gcd(ulli a, ulli b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

ulli lcm(ulli a, ulli b)
{
  return (a * b) / gcd(a, b);
}

int main(int argc, char const *argv[])
{
	ulli n, a, b, p, q, l, aval, bval, ans = 0;
	cin>>n>>a>>b>>p>>q;

	aval = n / a;
	bval = n / b;
	
	l = n / lcm(a, b);
	
	if(p > q)
		bval -= l;
	else
		aval -= l;
	
	ans += (aval * p) + (bval * q);

	cout<<ans<<'\n';
	return 0;
}