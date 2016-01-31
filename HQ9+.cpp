//http://codeforces.com/problemset/problem/133/A
#include <iostream>
#include <map>
using namespace std;

map<char,int> mp;

void init()
{
	mp['H']=1;
	mp['Q']=1;
	mp['9']=1;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(false);
	int n=0;
	string s;
	cin>>s;
	
	init();
	
	for(int i = 0; i < s.length(); i++)
		if(mp.find(s[i]) != mp.end())
			n++;
	
	if(n > 0)
		cout<<"YES"<<'\n';
	else
		cout<<"NO"<<'\n';
	
	return 0;
}