#include <iostream>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	unsigned long long int l, r, k, ans = 1, flag = 0;
	cin>>l>>r>>k;
	while(1)
	{
		if(ans >= l)
			break;
		else
			ans *= k;
	}
	while(ans >= l && ans <= r)
	{
		cout<<ans<<" ";
		ans *= k;
		flag = 1;
	}
	if(!flag)
		cout<<-1<<'\n';
	return 0;
}