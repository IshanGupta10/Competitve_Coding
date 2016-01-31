#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m,r,i,j,aux,temp,buffer;
	cin>>n>>m>>r;
	int a[n][m];
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			cin>>a[i][j];
		}
	}
	aux = n-1;
	temp = m-1;
	i=0;
	while(r>0)
	{
		for (j = aux; j >= 1; --j)
		{
			buffer = a[j][i];
			a[j][i] = a[j-1][i];
			a[j-1][i] = buffer;
		}
		for (j = temp; j >= 2; --j)
		{
			buffer = a[aux][j];
			a[aux][j] = a[aux][j-1];
			a[aux][j-1] = buffer;
		}
		r--;
	}
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}