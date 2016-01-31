#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string int2Roman(int k)
{
	int num,i=3;
	int power = pow(10,i);
	num=k;
	while(num>0)
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	string s = int2Roman(n);
	return 0;
}