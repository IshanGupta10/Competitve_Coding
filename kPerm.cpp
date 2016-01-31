#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getPerm(int n,int k)
{
	vector<int> v;
	unordered_map<int> mp;
	int temp,aux;
	for (int i = 1; i <= n; ++i)
	{
		temp = i-k;
		aux = i+k;
		if(temp != aux)
		{
			
		}
	}
}