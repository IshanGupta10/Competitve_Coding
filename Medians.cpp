// codeforces.com/problemset/problem/85/D
// SUM OF MEDIANS PROBLEM
// http://ideone.com/S5INgs


#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n,i=0,j=0,sum=0,z;		//variables
	char a[3];				//operation
	vector<int> v;			//vector of ease of access
	long int k;				//value to be entered <= 10^9
	cin>>n;
	vector<int> median;
	while(n>0)
	{
		cin>>a;
		if(strcmp(a,"add")==0)
		{
			cin>>k;
			v.push_back(k);
			sort(v.begin(),v.end());
		}
		else if(strcmp(a,"del")==0)
		{
			cin>>k;
			for(j=0;j<v.size();j++)
				if(v[j]==k)
					v.erase(v.begin()+j);
		}
		else if(strcmp(a,"sum")==0)
		{
			for (int i = 0; i < v.size(); ++i)
				if(i%5==2)
					sum = sum+v[i];
			//cout<<sum;
			median.push_back(sum);
			sum=0;
		}
		n--;
	}
	for (int i = 0; i < median.size(); ++i)
	{
		cout<<median[i];
		//if(i<median.size())
		//	cout<<'\n';
	}
	return 0;
}