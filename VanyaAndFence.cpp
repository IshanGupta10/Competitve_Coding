//http://codeforces.com/contest/677/problem/A
#include <iostream>
using namespace std;

int main() 
{
	long n, h, sum = 0, val;
	
	cin>>n>>h;
	
	for(int i = 0; i < n; ++i)
	{
		cin>>val;
		if(val > h)
			sum += 2;
		else
			sum += 1;
	}
	
	cout<<sum;
	
	return 0;
}