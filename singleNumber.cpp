#include <iostream>
#include <vector>
using namespace std;
void singleNumber(vector<int> &A)
{
	int _xor = A[0];
	for (int i = 1; i < A.size(); ++i)
	{
		_xor ^= A[i];
		cout<<"_xor "<<_xor<<'\n';	
	}
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
	singleNumber(v);
	return 0;
}