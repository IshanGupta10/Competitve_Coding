#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > prettyPrint(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details}
	vector<vector<int> > v;
	int size = (2*A) - 1;
	int i,j,number,x=1,k,n;
	number = A;
	for (int i = 0; i < size; ++i)
	{
		vector<int> row;
		v.push_back(row);
	}
	if(A==1)
		v[0].push_back(1);
	else if(A>1)
	{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			v[i].push_back(0);
		}
	}
	for (i = 0,j=size-1; i < size/2,j>size/2; ++i,j--)
	{
		for (int k = 0; k < size; ++k)
		{
			v[i][k]=number;
			v[j][k]=number;
		}
		number--;
	}
	number = A;
	n = size-2;
	for (i = 0,j=size-1; i < size/2,j>size/2; ++i,j--)
	{
		//for (k = 1,x=size-2; k <= size/2,x >= size/2; ++k,--x)
		for (k = x; k < n; ++k)
		{
			v[k][i]=number;
			v[k][j]=number;
		}
		x++;
		n = n--;
		number--;
	}
	number = A;
	int start = size-3;
	int stop =  2;
	n = 1+ size/2;
	k = size-2;
	for (i = start; i > n; i--)
	{
		for (j = stop; j < k ; ++j)
		{
			v[i][j]=number -2;
		}
		start--;
		stop++;
		k--;
		number--;
		//n++;
	}
	v[size-2][0]=A;
	v[size-2][size-1]=A;
	v[size/2][size/2]=1;
	}	
	return v;
}
int main(int argc, char const *argv[])
{
	vector<vector<int> > k;
	int n,si;
	cin>>n;
	si = (2*n)-1;
	for (int i = 0; i < si; ++i)
	{
		vector<int> row;
		k.push_back(row);
	}
	k = prettyPrint(n);
	for (int i = 0; i < si; ++i)
	{
		for (int j = 0; j < si; ++j)
		{
			cout<<k[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}