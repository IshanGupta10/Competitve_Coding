//http://codeforces.com/problemset/problem/633/C
//Incomplete
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

string toLower(const string &l)
{
	string aux;
	for(int i = 0; i < l.size(); ++i)
		if(l[i] >= 'A' && l[i] <= 'Z')
			aux += char((l[i] - 'A') + 97);
		else
			aux += l[i];
	return aux;
}

int main() 
{
	string s, t, k;
	set<string> st;
	int m, n;
	cin>>m;
	cin>>s;
	cin>>n;

	while( n-- )
	{
		cin>>k;
		k = toLower(k);
		reverse(k.begin(),k.end());
		bool exists = s.find(k) != std::string::npos;
		if(exists && k.size() != 1)
			st.insert(k);
		//cout<<k<<'\n';
	}
	// cout<<"Map elements"<<'\n';
	// for(auto i:st)
	// 	cout<<i<<'\n';
		
	// cout<<"String making"<<'\n';

	int siz = st.size(), x = 1;
	for(auto i:st)
	{
		string q = i;
		reverse(q.begin(),q.end());
		t += q;
		if(x < siz)
			t += " ";
		x++;
	}

	t[0] -= 32;
	cout<<t;
	return 0;
}