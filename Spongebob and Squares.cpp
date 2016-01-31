#include <iostream>
#include <set>
#include <vector>
#define int long long
using namespace std;
main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	vector< pair<int,int> > v;
	set< pair<int,int> > st;
	int x,s=0,t=0;cin>>x;
	for(int i=1;s<=x;++i)
	{
		s+=i*i;t+=i;
		if((x-s)%t==0)
		{
			st.insert({i,(x-s)/t+i});
			st.insert({(x-s)/t+i,i});
		}
	}
	cout<<st.size()<<'\n';
	for(auto i:st)	cout<<i.first<<' '<<i.second<<'\n';
}