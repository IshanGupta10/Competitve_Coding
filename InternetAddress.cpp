//http://codeforces.com/contest/245/problem/B
#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string s,t;
	int  i = 0, x;
	cin>>s;	
	
	if(s[0] == 'h')
	{
		t += s.substr(0,4) + "://";
		x = 4;
	}
	else
	{
		t += s.substr(0,3) + "://";
		x = 3;
	}
	
	for(; s[i]; i++)
		if(s[i] =='r' && s[i+1] == 'u')
			if(s[i-1] == 'p' && s[i-2] =='t')
				continue;
			else
				break;

	t += s.substr(x,i-x) + "." + s.substr(i,2);
	
	if(t.size() - 4 != s.size())
		t += "/" + s.substr(i+2,s.size() - i - 2);
	
	cout<<t;
	return 0;
}