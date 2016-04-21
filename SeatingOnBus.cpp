#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m, filler = 1;
	cin>>n>>m;
	int a[n][4];
	memset(a,0,sizeof(a));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if(j % 4 == 0)
			{
				a[i][j] = filler;
				filer += 2;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<'\n';
	}
	return 0;
}