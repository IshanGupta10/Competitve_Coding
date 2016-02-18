//http://codeforces.com/contest/630/problem/B
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() 
{
	long double ans = 1, n, t;
	cin>>n>>t;
	ans  = n*pow(1.000000011,t);
	cout<<setprecision(14)<<ans<<'\n';
	return 0;
}