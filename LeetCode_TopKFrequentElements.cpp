#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int, int> mp, ml;
        vector<pair<int,int>> p;
        int x = 0;
        vector<int> v;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(mp.find(nums[i]) == mp.end())
                mp[nums[i]] = 1;
            else
                mp[nums[i]]++;
        }
        
        for(map<int,int>::iterator i = mp.begin(); i != mp.end(); ++i)
        {
            p.push_back(make_pair(i->second,i->first));
        }
        
        sort(p.begin(), p.end());
        
        for(vector<pair<int,int>>::reverse_iterator i = p.rbegin(); i != p.rend(); ++i)
        {
            if(x == k)
                break;
            else
                v.push_back(i->second);
            x++;
        }
        return v;
    }

int main() 
{
	vector<int> q, v;
	int k, t, n;
	cin>>n;

	for(int i = 0; i < n; ++i)
	{
		cin>>t;
		q.push_back(t);
	}
	cin>>k;
	
	v = topKFrequent(q,k);
	
	for(auto i:v)
		cout<<i<<" ";
	
	return 0;
}