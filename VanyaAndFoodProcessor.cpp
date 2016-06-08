#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	unsigned long long int n, h, k, val, sum = 0, nextval = 0;

	cin>>n>>h>>k;

	for (int i = 0; i < n; ++i)
	{
		cin>>val;
		if(val < k)
			nextval += val;
		else if(val >= k)
		{
			sum += val / k;
			val = val % k;
			if(val != 0 && val < k)
				nextval += val;
		}
		if (nextval >= k)
		{
			sum += nextval / k;
			nextval %= k;
		}
	}
	
	sum += nextval / k;
	nextval %= k;
	
	if(nextval == 1)
		sum += 2;
	else if(nextval == 2)
		sum++;
	
	cout<<sum;
	return 0;
}