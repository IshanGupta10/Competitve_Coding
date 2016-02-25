//http://codeforces.com/contest/629/problem/A
#include <iostream>
using namespace std;

typedef unsigned long long int ulli;

int main()
{
	int n;
	ulli ans = 0;
	cin>>n;
	char a[n][n];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin>>a[i][j];

	for (int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			for (int k = j+1; k < n; ++k)
				if(a[i][j] == 'C' && a[i][k] == 'C')
					ans++;

	for (int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			for (int k = j+1; k < n; ++k)
				if(a[k][i] == 'C' && a[j][i] == 'C')
					ans++;

	cout<<ans<<'\n';
	return  0;		
}