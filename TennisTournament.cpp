//http://codeforces.com/contest/628/problem/A
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, b, p, count = 0, bo = 0, po = 0;
	cin>>n>>b>>p;
	po = n * p;
	bo = ( n - 1 )*( 2 * b +1 );
	//cout<<"bo "<<bo<<'\n';
	cout<<bo<<" "<<po<<'\n';
	return 0;
}
