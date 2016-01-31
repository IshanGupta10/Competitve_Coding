#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int coverPoints(vector<int> &X, vector<int> &Y) 
{
	vector<int>::iterator i,j;
	int count =0;
	for(i=X.begin(),j=Y.begin();i != X.end()-1,j != Y.end()-1;i++,j++)
	{
		count += fmax(abs(*i-*(i+1)),abs(*j-*(j+1)));
	}
	return count;
}

int main()
{
	vector<int> x,y;
	int i=0,n,a;
	cin>>n;
	cout<<"Enter x ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		x.push_back(a);
	}
	cout<<"Enter y ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		y.push_back(a);
	}
	a=coverPoints(x,y);
	cout<<a;
	return 0;
}