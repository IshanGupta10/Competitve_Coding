#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> repeatedNumber(const vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long int sum1=0,sum2=0,X,Y,k;
 	vector<int> B;
    vector<int>::const_iterator it;
    for (it = A.begin(); it != A.end(); ++it)
    {
    	sum1 +=*it;
    }
    for (long int i = 1; i <= A.size(); ++i)
    {
    	sum2 +=i;
    }
    X = sum1-sum2;
    cout<<"X "<<X;
    for (long int i = 1; i <= A.size(); ++i)
    {
    	sum2 +=(i*i);
    }
    for (it = A.begin(); it != A.end(); ++it)
    {
    	k = *it;
    	k = k*k;
    	sum1 +=k;
    }
    Y = (sum1 - sum2)/X;
    cout<<"Y "<<Y;
    k = (X+Y)/2;
    B.push_back(k);
    k=abs((X-Y)/2);
    B.push_back(k);
    return B;
}

int main()
{
	vector<int> v,t;
	int n,r;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>r;
		v.push_back(r);
	}
	t=repeatedNumber(v);
	cout<<t.front()<<" "<<t.back();
	return 0;
}