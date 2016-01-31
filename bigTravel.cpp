#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define MOD 1000000007

int main(int argc, char const *argv[])
{
	long long int sum=0,sum_x=0,sum_y=0,a,N,b;
	cin>>N;
	vector<int> x;
	vector<int> y;
	for (int i = 0; i < N; ++i)
	{
		cin>>a>>b;
		x.push_back(a);
		y.push_back(b);
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	// for(int i = 0; i < N; i++)
	// {
	// 	for (int j = i+1; j < N; ++j)
	// 	{
	// 		sum += abs(x[i]-x[j])+abs(y[i]-y[j]); 
	// 		if(sum > 1000000007)
	// 			sum = sum%1000000007;
	// 	}
	// }
	for (int i = 0; i < N; ++i)
	{
		sum += (i*x[i] - sum_x)%MOD;
		sum += (i*y[i] - sum_y)%MOD;
		sum_x += x[i];
		sum_y += y[i];
		//cout<<sum<<'\n';
	}
	cout<<sum%1000000007;
	return 0;
}