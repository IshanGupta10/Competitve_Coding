//http://codeforces.com/contest/710/problem/0
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	char x;
	int n;

	cin>>s;

	x = s[0];
	n = s[1] - '0';

	if(s == "a8" || s == "a1" || s == "h8" || s == "h1")
		cout<<3<<'\n';
	else if((n > 1 && n < 8) && (x > 'a' && x < 'h'))
		cout<<8<<'\n';
	else
		cout<<5<<'\n';
	return 0;
}