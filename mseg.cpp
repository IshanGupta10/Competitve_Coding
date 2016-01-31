#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
//vector<pair> mSeg(int a, vector<int> &A)
vector<int> mSeg(int a, vector<int> &A)
{
	//pair<int,int> p;
	//vector<pair> v;
	vector<int> k;
	cout<<"a "<<a<<endl;
	int sum=0;
	cout<<"Sum "<<sum<<endl;
	for (int i = 0; i <A.size()-1 ; ++i)
	{
		cout<<"Sum "<<sum<<endl;
		if((A[i]*A[i+1])%a==0)
		{
			sum = (A[i]*A[i+1])/a;
			cout<<"Sum "<<sum<<endl;
			k.push_back(sum);
		}
	}
	sort(k.begin(),k.end());
	int aux = k.front()-1;
	sort(A.begin(),A.end());
	//if(A.front()-1==aux)
	return k;
}
int main(int argc, char const *argv[])
{
	int n,t,factor;
	cin>>n;
	vector<int> x,y;
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		x.push_back(t);
	}
	cin>>factor;
	cout<<"Factor "<<factor<<endl;
	y=mSeg(factor,x);
	for (int i = 0; i < y.size(); ++i)
	{
		cout<<y[i]<<" ";
	}
	return 0;
}