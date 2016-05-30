#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> v;
	int maxEle = 0, minEle = 0, n, t;
	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		v.push_back(t);
	}

	minEle = v[0];
	maxEle = v[0];

	for(int i = 0; i < n; i++)
  	{
  		if(v[i] < minEle)
  			minEle = v[i];
  		if(v[i] > maxEle)
  			maxEle = v[i];       
  	}

  	cout<<abs(maxEle - minEle);
	return 0;
}