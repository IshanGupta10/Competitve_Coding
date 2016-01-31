#include <iostream>
#include <vector>
#include <string>
using namespace std;

int value(char c)
{
	switch(c)
	{
		case 'I':	return 1;
					break;
		case 'V':	return 5;
					break;
		case 'X':	return 10;
					break;
		case 'L':	return 50;
					break;
		case 'C':	return 100;
					break;
		case 'D':	return 500;
					break;
		case 'M':	return 1000;
					break;
	}
}
int romanToInt(string A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int sum=0,t;
	vector<int> v;
	for (int i = 0; i < A.length(); ++i)
	{
		t=value(A[i]);
		v.push_back(t);
	}
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		if(*i < *(i+1))
			sum -= *i;
		else
			sum += *i;
	}
	return sum;
}
int main(int argc, char const *argv[])
{
	string k="DCCCLXXVI";
	int x = romanToInt(k);
	cout<<x;
	return 0;
}