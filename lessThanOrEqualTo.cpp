#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int m,n,val;
	cin>>m>>n;
	int a[n];

	for (int i = 0; i < n; ++i)
		cin>>a[i];
	
	sort(a,a+n);
	
	for (int i = 0; i < m; ++i)
	{
		cin>>val;
		int count = lower_bound(a,a+n,val+1)-a;
		if(i)
			cout<<" ";
		cout<<count;
	}
	
	cout<<endl;
	return 0;
}