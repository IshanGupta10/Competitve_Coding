#include <iostream>
using namespace std;

int gcd_bin(int u, int v) 
{
	int t, k;
	u = u < 0 ? -u : u; /* abs(u) */
	v = v < 0 ? -v : v; 
  	if (u < v) 
  	{
    	t = u;
    	u = v;
    	v = t;
  	}
  	if (v == 0)
    	return u;
	k = 1;
  	while (u & 1 == 0 && v & 1 == 0) 
  	{ /* u, v - even */
    	u >>= 1; v >>= 1;
    	k <<= 1;
  	}
 
  	t = (u & 1) ? -v : u;
  	while (t) 
  	{
    	while (t & 1 == 0) 
      		t >>= 1; 
    	if (t > 0)
      		u = t;
    	else
      		v = -t;
	    t = u - v;
  	}
  	return u * k;
}

int main(int argc, char const *argv[])
{
	int a, b, m;
	cin>>a>>b>>m;
	if (gcd_bin(b,m) != 1)
		cout<<"Not Possible";
	else
		cout<<(gcd_bin(b,m)*a)%m;
	return 0;
}