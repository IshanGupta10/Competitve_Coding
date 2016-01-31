//https://www.hackerearth.com/september-easy-15/algorithm/acronym-2/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k,n;
	string q;
	cin>>k;
	map<string, int> A;
	for (int i = 0; i < k; ++i)
	{
		cin>>q;
		A[q]=1;
	}
	string result="";
	cin>>n;
	while(n--)
	{
		cin>>q;
		//cout<<q<<endl;
		if(A.find(q)==A.end())
		{
			result +=q[0]-32;
			result +='.';
		}
	}
	n = result.length()-1;
	for (int i = 0; i < n; ++i)
	{
		cout<<result[i];
	}
	cout<<'\n';
	return 0;
}