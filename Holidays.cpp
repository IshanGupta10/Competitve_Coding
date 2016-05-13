#include <iostream>
using namespace std;

int main() 
{
	int m, n, min = 0, max = 0;
	bool flag = true;
	
	cin>>n;
	m = n;
	
	while(n >= 0)
	{
		if(flag)
		{
			n -= 5;
			flag = false;
		}
		else
		{
			if(n <= 2 && n >= 0)
			{
				min += n;
				break;
			}
			n -= 2;
			flag = true;
			min += 2;
		}
	}
	
	flag = true;
	
	while(m >= 0)
	{
		if(flag)
		{
			if(m <= 2 && m >= 0)
			{
				max += m;
				break;
			}
			m -= 2;
			flag = false;
			max += 2;
		}
		else
		{
			m -= 5;
			flag = true;
		}
	}
	cout<<min<<" "<<max;
	return 0;
}