#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>

using namespace std;

bool mycompare(string X, string Y)
{
	string XY = X.append(Y);
	string YX = Y.append(X);
	return XY.compare(YX)>0?true:false;
}

string largestNumber(const vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	vector<string> v;
	string s,c;
	vector<int>::const_iterator it;
	for (it = A.begin(); it != A.end(); ++it)
	{
		c = to_string(*it);
		v.push_back(c);
		cout<<c;
	}
	cout<<"Check ";
	for (std::vector<char>::iterator i = v.begin(); i != v.end(); ++i)
	{
		cout<<*i;
		s.push_back(*i);
	}
	//cout<<s;
	return s;
}

int main(int argc, char const *argv[])
{
	vector<int> k;
	int n,t;
	cin>>n;
	string q;
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		k.push_back(t);
	}
	q=largestNumber(k);
	cout<<q;
	return 0;
}