#include "iostream"
#include "vector"
using namespace std;

void rotate(vector<vector<int> > &A) 
{
	int i,j,row,column,n,x,temp,r=0;
	row = A.size();
	column = A[0].size();
	//cout<<row<<'\n';
	//cout<<column;
	n = row;
	while(r < n) 
	{
		x = r;
		while(x < n) 
		{
			temp = A[r][x];
			A[r][x] = A[x][r];
			A[x][r] = temp;
			x++;
		}
		r++;
	}
	for (i = 0; i < row; ++i)
	{
	//	cout<<'[';
		for (j = 0; j < column; ++j)
		{
			cout<<A[i][j]<<' ';
		}
	    cout<<'\n';
	//	cout<<']'<<" ";
	}
	n = row;
	x=n-1;
	r=0;
	while(r < x) 
	{
 
		int y = 0;
		while(y < n) 
		{
			temp = A[y][r];
			A[y][r] = A[y][x];
			A[y][x] = temp;
			y++;
		}
		r++;
		x--;
	}
	for (i = 0; i < row; ++i)
	{
		cout<<'[';
		for (j = 0; j < column; ++j)
		{
			cout<<A[i][j]<<' ';
		}
		cout<<']'<<" ";
	}
}
int main()
{
	vector<vector<int> > v;
	int r,c,i=0,j=0,t;
	cin>>r>>c;
	for (i = 0; i < r; ++i)
	{
		vector<int> row;
		v.push_back(row);
	}
	for (i = 0; i < r; ++i)
	{
		for (j = 0; j < c; ++j)
		{		
			cin>>t;
			v[i].push_back(t);
		}
	}
	rotate(v);
	return 0;
}