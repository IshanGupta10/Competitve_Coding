//http://codeforces.com/contest/667/problem/A
#include <bits/stdc++.h>
using namespace std;


#define pi 3.14159265359

int main(int argc, char const *argv[])
{
	double h, d, v, e, ans = 0;
	cin>>d>>h>>v>>e;

	double speed = (4 * v) / (pi * d * d);

	if(speed < e)
		cout<<"NO"<<'\n';
	else
	{
		ans = h /  ( speed - e);
		cout<<"YES"<<'\n'<<setprecision(10)<<ans<<'\n';  
	}
	return 0;
}