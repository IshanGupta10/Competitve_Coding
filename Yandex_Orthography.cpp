#include <bits/stdc++.h>
using namespace std;

int diffStrings(string a, string b)
{
	int count = 0;

	for (int i = 0; i < a.size(); ++i)
		if(a[i] != b[i])
			count++;

	return count;
}

int getSum(vector<int> &z)
{
	int sum = 0;

	for (int i = 0; i < z.size(); ++i)
		sum += z[i];

	return sum;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	
	string s[n];
	vector<int> v;	
	map<string, vector<int>> mp;

	for (int i = 0; i < n; ++i)
		cin>>s[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int diff = diffStrings(s[i], s[j]);
			v.push_back(diff);
		}
	
		mp[s[i]] = v;
		v.clear();
	}

	for (int i = 0; i < n; ++i)
	{
		v = mp[s[i]];
	
		int sum = getSum(v);

		if(sum <= n-1)
		{
			cout<<s[i];
			return 0;
		}

    	if(sum == 0)
        {
        	cout<<s[i];
        	return 0;
        }
	}
	
	cout<<-1;
	
	return 0;
}