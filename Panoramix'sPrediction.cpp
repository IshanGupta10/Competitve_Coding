//http://codeforces.com/problemset/problem/80/A
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

bool isPrime(int n)
{
	if(n == 2)
		return true;
    if(n == 3)
    	return true;
    if (n % 2 == 0)
        return false;
    if(n % 3 == 0)
    	return false;

	int i = 5 , w = 2;

    while (i * i <= n)
    {
    	if (n % i == 0)
        	return false;
        i += w;
    	w = 6 - w;
    }
    return true;
}

void init()
{
	for(int i = 1; i <= 50; ++i)
		if(isPrime(i))
			v.push_back(i);
}

int main() 
{
	int n, m;
	cin>>n>>m;
	init();
	if(isPrime(n) && isPrime(m))
	{
		for(int i = 0; i < v.size(); ++i)
			if(v[i] == n)
				if(v[i+1] == m && i != v.size())
					cout<<"YES"<<'\n';
				else
					cout<<"NO"<<'\n';
	}
	else
		cout<<"NO"<<'\n';
	return 0;
}