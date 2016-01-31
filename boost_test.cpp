#include <iostream>
#include <boost/lexical_cast.hpp>

using namespace std;
using boost::lexical_cast;

int main()
{
	int s = lexical_cast<int>("23456789");
	cout<<s<<'\n';
	return 0;
}