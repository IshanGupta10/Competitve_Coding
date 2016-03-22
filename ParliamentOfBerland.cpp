//http://www.codeforces.com/contest/644/problem/A
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n, a, b;
	cin>>n>>a>>b;
	
	int mat[a][b];
	
	memset(mat,0,sizeof(mat));
	
	if(n > a * b)
		cout<<-1<<'\n';
	else
	{
		int i = 0 , j = 0;
		for(i = 0; i < a; ++i)
		{
			if(i % 2 != 0)
			{
				for( j = b - 1; j >= 0; --j)
				{	
					if(n == 0)
						n = 0;
					mat[i][j] = n;
					n--;
				}
			}
			else
			{
				for( j = 0; j <= b - 1; ++j)
				{
					if(n == 0)
						n = 0;
					mat[i][j] = n;
					n--;
				}
			}
		}

		for(int i = 0; i < a; ++i)
			for(int j = 0; j < b; ++j)
				if(mat[i][j] <= 0)
					mat[i][j] = 0;

		for(int i = 0; i < a; ++i)
		{
			for(int j = 0; j < b; ++j)
				cout<<mat[i][j]<<" ";
			cout<<'\n';
		}
	}
	return 0;
}