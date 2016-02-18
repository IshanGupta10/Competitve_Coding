//http://codeforces.com/contest/630/problem/R
#include <iostream>
using namespace std;

typedef unsigned long long int ulli;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ulli n;
	cin>>n;
	if( n % 2 )
		cout<<1<<'\n';
	else
		cout<<2<<'\n';
	return 0;
}