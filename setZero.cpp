#include <iostream>
#include <vector>
#include <utility>
using namespace std;
void setZeroes(vector<vector<int> > &A) 
{
	pair<int,int> p[10];
	int k=0,row,o,col;
	for (int i = 0; i < A.size(); ++i)
	{
		o = A[i].size();
		for (int j = 0; j < o; ++j)
		{
			if(A[i][j]==0)
			{
				p[k]= make_pair(i,j);
				k++;
			}
		}
	}
	for (int i = 0; i < k; ++i)
	{
		row = p[i].first;
		col = A[row].size();
		for (int j = 0; j < col; ++j)
		{
			A[row][j]=0;
		}
	}
	for (int i = 0; i < k; ++i)
	{
		col = p[i].second;		
		//row = A[row].size();
		for (int j = 0; j < A.size(); ++j)
		{
			A[j][col]=0;
		}
	}
	for (int i = 0; i < A.size(); ++i)
	{
		int c=A[i].size();
		for (int j = 0; j < c; ++j)
		{
			cout<<A[i][j]<<" ";
		}
	    cout<<'\n';
	//	cout<<']'<<" ";
	}
}
int main(int argc, char const *argv[])
{
	vector<vector<int> > v;
	int n,t;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>t;
			v[i].push_back(t);
		}
	}
	setZeroes(v);
	return 0;
}