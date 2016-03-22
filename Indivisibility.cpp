//http://codeforces.com/contest/630/problem/K
#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long int ulli;

int main() 
{
	ulli n, x;
	cin>>n;
	if(n <= 10)
		cout<<1<<'\n';
	else
	{
		x = ceil((n/log(n))-3);
		cout<<x<<'\n';
	}
	return 0;
}