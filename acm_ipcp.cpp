#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
vector<vector<int> > getSubsets(vector<int> a)
{

    if(a.size() == 1)
    {
        vector<vector<int> > temp;
        temp.push_back(a);

        vector<int> b;
        temp.push_back(b);

        return temp;
    }
    else
    {

        int last = a[a.size() - 1];

        a.pop_back();

        vector<vector<int> > without = getSubsets(a);

        vector<vector<int> > with = without;

        for(int i=0;i<without.size();i++){
            with[i].push_back(last);
        }

        vector<vector<int> > total;

        for(int j=0;j<without.size();j++){
            total.push_back(without[j]);
        }

        for(int k=0;k<with.size();k++){
            total.push_back(with[k]);
        }
        return total;
    }
}

unsigned int gcd(unsigned int a, unsigned int b)
{
    while (a != b)
    {
        if (a > b)
            return gcd(a - b, b);
        else
            return gcd(a, b - a);

    }
    return a;
}

int getGCD(vector<int> &s)
{
	int ans = s[0];
	for(int i=1;i<s.size();i++)
	{
    	ans = gcd(ans,s[i]); 
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n,t,T,pro=1;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<int> v,q;
		vector<vector<int> > x;
		for (int i = 0; i < n; ++i)
		{
			cin>>t;
			v.push_back(t);
		}
		x = getSubsets(v);
		sort(x.begin(),x.end());
		for (int i = 0; i < x.size(); ++i)
		{
			int aux = getGCD(x[i]);
			//cout<<aux<<" ";
			q.push_back(aux);
			//cout<<endl;
		}
		//cout<<endl;
		for (int i = 0; i < q.size(); ++i)
		{
			pro *=q[i];
		}
		//cout<<pro<<endl;
		cout<<pro%MOD;
		pro =1;
	}
	return 0;
}