//http://codeforces.com/contest/630/problem/D
#include <iostream>
using namespace std;

typedef unsigned long long int ulli;

int main() 
{
	ulli n, ans = 0;
	cin>>n;
	if(n == 0)
		ans = 1;
	else
		ans = 1+(6*((n*(n+1))/2));
	cout<<ans<<'\n';
	return 0;
}