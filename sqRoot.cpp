#include <iostream>
using namespace std;
int sqRoot(int A)
{
	if(A==0)
	return 0;
	long int low,mid,high,q,p;
	high = A/2;
	//cout<<high<<endl;
	low = high/2;
	//cout<<low<<endl;
	while(low <= high)
	{
		//cout<<"Hello! "<<endl;
		q= low*low;
		if(A > q)
		{
			p = high*high;
			if(A < p)
			{
				//cout<<"Yellow! "<<endl;
				break;
			}
		}
		high = high/2;
		//cout<<"high "<<high<<endl;
		low = high/2;
		//cout<<"low "<<low<<endl;
	}
	if(high*high == A)
	return high;
	if(low*low == A)
	return low;
	while(low <= high)
	{
		mid = (low+high)/2;
		//cout<<"High "<<high<<endl;
		//cout<<"Low "<<low<<endl;
		//cout<<"Mid "<<mid<<endl;
		if(mid*mid > A)
			high = mid;
		if(mid*mid < A)
			low = mid;
		if(mid*mid == A)
			return mid;
		if(high-low == 1)
			return low;
		//cout<<"High "<<high<<endl;
		//cout<<"Low "<<low<<endl;
		//cout<<"Mid "<<mid<<endl;
	}
	return mid;
}
int main(int argc, char const *argv[])
{
	int X,y;
	cin>>X;
	y = sqRoot(X);
	cout<<y<<endl;
	return 0;
}