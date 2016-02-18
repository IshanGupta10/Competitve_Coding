//http://codeforces.com/contest/630/problem/Q
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define pi 3.14159265359

int main() 
{
	long double sum = 0, x, y, z;
	cin>>x>>y>>z;

	z = (pow(z,3) * (5 + sqrt(5))) / 24;
	y = (pow(y,3) * sqrt(2)) / 6;
	x = (pow(x,3) * sqrt(2)) / 12;

	sum = x + y + z;

	cout<<setprecision(14)<<sum<<'\n';
	return 0;
}