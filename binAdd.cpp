#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
void addBinary(string A, string B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	string s,q;
	vector<int> u,v;
	int a;
	for (int i = 0; i < A.length(); ++i)
	{
		a=A[i];
		u.push_back(a-48);
	}
	// cout<<"Vector u: ";
	// for (std::vector<int>::iterator i = u.begin(); i != u.end(); ++i)
	// {
	// 	cout<<*i<<" ";
	// }
	// cout<<endl;
	for (int i = 0; i < B.length(); ++i)
	{
		a=B[i];
		v.push_back(a-48);
	}
	if(B.length() < A.length())
	{
		for (i=v.end(),j=u.end() ; i!=v.end(), j!=u.end(); --i,j--)
		{
				
		}