//http://codeforces.com/problemset/problem/158/A
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,k,count = 0;
	cin>>n>>k;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin>>a[i];
	int a_k = a[k-1];
	sort(a,a+n);
	for(int i = 0; i < n; ++i)
		if(a[i] >= a_k && a[i] > 0)
			count++;
	cout<<count<<'\n';
	return 0;
}