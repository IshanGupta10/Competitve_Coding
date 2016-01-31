//http://codeforces.com/problemset/problem/393/A
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() 
{
	map<char,int> mp,mpn;
	string s,n = "nineteen";
	int aux = 0;
	int count[] = {100009, 100009, 100009, 100009};
	bool flag = false;
	for (int i = 0; i < n.size(); ++i)
		if(mpn.find(n[i]) != mpn.end())
			mpn[n[i]]++;
		else
			mpn[n[i]] = 1;
	cin>>s;

	for (int i = 0; i < s.size(); ++i)
		if(mp.find(s[i]) != mp.end())
			mp[s[i]]++;
		else
			mp[s[i]] = 1;

	map<char,int>::iterator i;

	for(i = mp.begin(); i != mp.end(); ++i)
		if(mpn.find(i->first) != mpn.end())
		{	
			//cout<<i->first<<" "<<i->second<<" "<<mpn[i->first]<<endl;
			if(i->second%mpn[i->first] == 0)
			{
				count[aux] = i->second/mpn[i->first];
				aux++;
			}
			else
				count[aux] = 10000009;
		}
		else
			continue;
			
		// for(int i = 0; i < 4; ++i)
		// 	cout<<count[i]<<" ";
		// cout<<endl;
		cout<<*min_element(count,count+4)<<endl;
	return 0;
}