//http://codeforces.com/problemset/problem/471/A
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

map<int, int> mp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a[6];
	vector<int> v;
	for(int i = 0; i < 6; i++)
		cin>>a[i];
	
	sort(a,a+6);

	for (int i = 0; i < 6; ++i)
		if(mp.find(a[i])!=mp.end())
			mp[a[i]]++;
		else
			mp[a[i]]=1;

	if(mp.size() == 1)
		cout<<"Elephant"<<'\n';
	else if(mp.size() == 2)
	{
		for(auto &i : mp)
			v.push_back(i.second);
		sort(v.begin(),v.end());
	
		if(v[0] == 2 && v[1] == 4)
			cout<<"Elephant"<<'\n';
		else if(v[0] == 1 && v[1] == 5)
			cout<<"Bear"<<'\n';
		else
			cout<<"Alien"<<'\n';
	}
	else if (mp.size() == 3)
	{
		map<int,int>::iterator x,y;
		sort(mp.begin(),mp.end());
		x=mp.begin();
		y=x++;		
		cout<<mp.size()<<" ";
		cout<<x->first<<" "<<x->second<<'\n';
		cout<<y->first<<" "<<y->second<<" ";
		// if(x->second == 1 && y->second == 1)
		// 	cout<<"Bear"<<'\n';
		// if(x->second == 2 && y->second == 2)
		// 	cout<<"Alien"<<'\n';
	}
	else
	//	cout<<"Alien"<<'\n';
	return 0;
}