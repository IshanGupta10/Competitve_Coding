//http://codeforces.com/problemset/problem/53/A
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,flag = 0;
	string test;
	cin>>test>>n;
	string s[n];

	for (int i = 0; i < n; ++i)
		cin>>s[i];
	sort(s,s+n);

	for (int i = 0; i < n; ++i)
	{
		string str = s[i].substr(0,test.size());
		if(str == test)
		{
			flag = 1;
			cout<<s[i]<<'\n';
			break;
		}
	}

	if(!flag)
		cout<<test<<'\n';
	//cout<<s[i];
	// for (int i = 0; i < n; ++i)
	// 	cout<<s[i]<<'\n';
	return 0;
}