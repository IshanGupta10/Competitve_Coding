#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,sum=0;
	cin>>n>>m;
	if(n==0 || m==0)
		cout<<0;
	long int a[m][n];
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>a[i][j];
		}
	}
	//cout<<"Input: "<<endl;
	// for (int i = 0; i < m; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }	
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			sum = sum+a[j][i];
		}
		//cout<<i<<" Sum values "<<sum<<endl;
		v.push_back(sum);
		sum=0;
	}
	int max = *max_element(v.begin(),v.end());
	for (int i = 0; i < v.size(); ++i)
	{
		if(v[i]==max)
		{
			cout<<i+1;
			break;
		}
	}
	return 0;
}