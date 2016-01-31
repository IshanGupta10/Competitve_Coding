#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int atoi(string &A)
int integer(string A,string B)
{
	int x = atoi(A);
	int y = atoi(B);
	long long int z = x*y;
	return z;
}
int main(int argc, char const *argv[])
{
	string a = "123";
	string b = "123";
	int q = integer(a,b);
	cout<<q<<endl;
	return 0;
}