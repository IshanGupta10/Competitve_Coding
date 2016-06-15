#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll int n,a[100010];
ll int dp[100010][2][2][2][2][2];//index,start,ignore1,ignore2,end,element removed or not
ll int ke[100010]; //kadane from end
ll int pre[100010];
ll int myfind(ll int index,ll int start,ll int ignore1,ll int ignore2,ll int end,ll int remove)
{
	if(dp[index][start][ignore1][ignore2][end][remove]==-1) //not yet been calculated
	{
		ll int ans;
		if(index==n)
		{
			if(ignore1==1 && remove==1)
			ans=0;
			else
			ans=INT_MIN;
		}
		else
		{
			if(end==1)
			ans=0;
			else if(ignore2==1)
			{
				ans=max(a[index]+myfind(index+1,start,ignore1,ignore2,end,1),a[index]+myfind(index+1,start,ignore1,ignore2,1,1));
			}
			else if(ignore1==1)
			{
				ans=max(max(myfind(index+1,start,ignore1,ignore2,end,1),myfind(index+1,start,ignore1,1,end,1)),myfind(index+1,start,ignore1,1,1,1));
			}
			else if(start==1)
			{
				ans= max(a[index]+myfind(index+1,start,ignore1,ignore2,end,remove),a[index]+myfind(index+1,start,1,ignore2,end,remove));
			}
			else
			{
				ans=max(myfind(index+1,start,ignore1,ignore2,end,1),myfind(index+1,1,ignore1,ignore2,end,1));		
			}
		}
		dp[index][start][ignore1][ignore2][end][remove]=ans;
	}
	return dp[index][start][ignore1][ignore2][end][remove];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll int i,j,k,l,m,x,ans,prev;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<2;j++)
		{
			for(k=0;k<2;k++)
			{
				for(l=0;l<2;l++)
				{
					for(m=0;m<2;m++)
					{
						for(x=0;x<2;x++)
						dp[i][j][k][l][m][x]=-1; //not yet been calculated
					}
				}
			}
		}
	}
	ans=max(myfind(0ll,0,0,0,0,1),myfind(0ll,1,0,0,0,0));
	cout<<ans<<endl;
	return 0;
}
