#include <iostream>
#include <cmath>
using namespace std;

int power(int x)
{
	int mul=1;
	for(int i=0;i<x;i++)
		mul = mul*10;
	return mul;
}		

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int k,d,num=0;
	cin>>k>>d;
	if(d==0 && k==1)
		cout<<0<<'\n';
	else if(d > 0)
	{	
		k--;
		num = d*power(k);
		cout<<num<<'\n';
	}
	else if(d==0 && k>1)
		cout<<"No solution"<<'\n';
	else
		cout<<"No solution"<<'\n';
	return 0;
}