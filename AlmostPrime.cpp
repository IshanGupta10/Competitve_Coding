//http://codeforces.com/problemset/problem/26/A
#include <iostream>
#include <vector>
using namespace  std;

vector<int> v;

bool isPrime(int n)
{
    if(n == 2)
    	return 1;
    if(n%2 == 0)
    	return 0;
    for(int i = 3; i*i<=n; i+=2)
        if(n%i == 0)
        	return 0;
    return 1;
}

void init()
{
	for (int i = 2; i <= 55; ++i)
		if(isPrime(i))
			v.push_back(i);
}

int main(int argc, char const *argv[])
{
	int n,count=0,aux=0;
	cin>>n;
	init();

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < v.size() ; ++j)
			if(i%v[j]==0)
				aux++;
		if(aux == 2)
			count++;
		aux = 0;
	}
	cout<<count<<'\n';
	return 0;
}
