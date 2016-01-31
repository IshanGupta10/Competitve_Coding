//http://codeforces.com/contest/26/problem/A
#include <iostream>
#include <set>
#include <cmath>
using namespace std;

set<int> st;

void primeFactors(int n)
{
    while (n%2 == 0)
    {
        st.insert(2);
        n = n/2;
    }
   for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            st.insert(i);
            n = n/i;
        }
    }
    if (n > 2)
        st.insert(n);
}

int main(int argc, char const *argv[])
{
	int n,count=0;
	cin>>n;
	for(int i = 6; i <= n; i++)
	{
		primeFactors(i);
		if(st.size() == 2)
		{
			for(auto &it:st)
    			cout<<it<<" ";
    		cout<<'\n';
			count++;
			cout<<i<<" ";
		}
		else
			st.clear();
		cout<<'\n';
	}
	cout<<'\n'<<count<<'\n';
	return 0;
}