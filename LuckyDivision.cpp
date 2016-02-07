//http://codeforces.com/problemset/problem/122/A
#include <iostream>
#include <map>
using namespace std;

int main() 
{
	map<int,int> mp;
	mp.insert(make_pair(1,4));
	mp.insert(make_pair(2,7));
	mp.insert(make_pair(3,44));
	mp.insert(make_pair(4,47));
	mp.insert(make_pair(5,74));
	mp.insert(make_pair(6,77));
	mp.insert(make_pair(7,444));
	mp.insert(make_pair(8,447));
	mp.insert(make_pair(9,474));
	mp.insert(make_pair(10,477));
	mp.insert(make_pair(11,744));
	mp.insert(make_pair(12,747));
	mp.insert(make_pair(13,774));
	mp.insert(make_pair(14,777));
	
	int n;
	cin>>n;
	for(int i = 1; i <= 14; ++i)
		if(n % mp[i] == 0)
		{
			cout<<"YES"<<'\n';
			return  0;
		}
	cout<<"NO"<<'\n';
	return 0;
}
