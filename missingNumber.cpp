#include <iostream>
#include <vector>
using namespace std;
int singleNumber(vector<int> &A)
{
	int sum = 0, n = A.size();
	for (int i = 0; i < A.size(); ++i)
	{
		sum += A[i];
		// _xor ^= A[i];
		// cout<<"_xor "<<_xor<<'\n';
	}
	//cout<<"Number "<<(n*(n+1)/2) - sum;
	return n*(n+1)/2 -sum;
	// xor_ = _xor ^ A.size();
	// for (int i = 1; i < A.size(); ++i)
	// {
	// 	_xor ^= i;
	// cout<<"xor_ "<<xor_<<'\n';	
	// }
	// _xor--;
	// cout<<"_xor "<<_xor;
}
int main(int argc, char const *argv[])
{
	vector<int> v;
	int n,t;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		v.push_back(t);
	}
	t = singleNumber(v);
	cout<<t<<'\n';
	return 0;
}