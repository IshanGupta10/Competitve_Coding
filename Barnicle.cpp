// http://codeforces.com/problemset/problem/697/B
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s, t = "";
	int power;
	vector<string> v;

	cin>>s;
	
	unsigned size_t_1 = s.find(".");
	unsigned size_t_2 = s.find("e");
	
	v.push_back(s.substr(0, size_t_1));
	v.push_back(s.substr(size_t_1 + 1, size_t_2 - 2));
	v.push_back(s.substr(size_t_2 + 1, s.size()));
	
	t += v[0];
	
	if(v[2].size() == 3)
		power = (v[2][0] - '0') * 100 + (v[2][1] - '0') * 10 + v[2][2] - '0';		
	else if(v[2].size() == 2)
		power = (v[2][0] - '0') * 10 + v[2][1] - '0';
	else if(v[2].size() == 1)
		power = v[2][0] - '0';
		
	// cout<<"power = "<<power<<'\n';
	if(v[2] == "0" && v[1] == "0")
		t = t;
	else if(v[1].size() > power)
	{
		for(int i = 0; i < power; ++i)
			t += v[1][i];
		t += '.';
		t += v[1].substr(power,v[1].size());
	}
	else if(v[1].size() == power)
	{
		t += v[1];
	}
	else
	{
		if(v[1] != "0")
		{
			t += v[1];
			for(int i = 0; i < power - v[1].size(); ++i)
				t += '0';
		}
		else
		{
			for (int i = 0; i < power; ++i)
				t += '0';
		}
	}
	
	// for(auto i : v)
	// 	cout<<i<<'\n';
	
	// cout<<"t = "<<t<<'\n';
	
	cout<<t<<'\n';
	return 0;
}