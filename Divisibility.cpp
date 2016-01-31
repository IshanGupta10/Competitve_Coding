//http://codeforces.com/problemset/problem/597/A
#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll a,b,k,count;
	cin>>k>>a>>b;
	ll left = a%k == 0 ? a : a + (k - a%k);
   	ll right = b%k == 0 ? b : b - b%k;
    count = (right - left)/k + 1;
    cout<<count<<'\n';
	return 0;
}