#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;

pair<ulli, ulli> p;

ulli power(ulli k)
{
	return k * k * k;
}


void dfs(ulli m, ulli mblocks, ulli mvol)
{
	if(m == 0)
	{
		p = max(p, make_pair(mblocks, mvol));
		return;
	}

	ulli x = 1;
	
	while(power(x + 1) <= m)
		++x;
	cout<<"m "<<m<<" mblocks "<<mblocks<<" mvol "<<mvol<<'\n';
	dfs(m - power(x), mblocks + 1, mvol + power(x));

	if(x - 1 >= 0)
		dfs(power(x) - 1 - power(x - 1), mblocks + 1, mvol + power(x - 1));
}

int main(int argc, char const *argv[])
{
	ulli m;

	cin>>m;

	dfs(m, 0 , 0);

	cout<<p.first<<" "<<p.second<<'\n';

	return 0;
}