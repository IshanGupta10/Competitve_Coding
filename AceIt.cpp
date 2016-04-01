#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	int ans = 0;
	cin>>s;
	
 	for (int i = 1; i < s.size(); ++i)
 	{
 		if(s[i] == '1')
 			ans += 10;
 		else
 			ans += (s[i] - '0');
 	}
	cout<<ans+1<<'\n';
	return 0;
}