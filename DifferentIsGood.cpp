#include <bits/stdc++.h>
using namespace std;

int main() 
{
	string s;
	int n, sum = 0, t, flag = 0;
	int a[26] = {0};
	cin>>n;
	cin>>s;
	
	for(int i = 0; i < n; ++i)
	{
		t = s[i] - 96;
		a[--t]++;
	}

	// for(int i = 0; i < 26; ++i)
	// 	cout<<a[i]<<" ";
		
	// cout<<'\n';
	for (int i = 0; i < 26; ++i)
	{
		if(a[i] == s.size() && a[i] > 26)
			flag++;
	}

	if(n > 26)
		cout<<-1;
	else
	{	
		for(int i = 0; i < 26; ++i)
			if(a[i] > 1)
				sum += a[i] - 1;		
		cout<<sum;
	}
	return 0;
}