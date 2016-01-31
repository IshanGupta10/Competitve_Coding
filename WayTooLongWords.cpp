//http://codeforces.com/problemset/problem/71/A
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	string s;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>s;
		if (s.size() <= 10)
			cout<<s<<'\n';
		else
			cout<<s[0]<<s.size()-2<<s[s.size()-1]<<'\n';
	}
	return 0;
}