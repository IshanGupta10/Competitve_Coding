#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPrime(int x) 
{
    for (int i = 2; i < x / 2; i++) 
    {
        if (x % i == 0) 
        {
                return false;
        }
    }
    return true;
}

vector<int> primesum(int A) 
{
    vector<int> v;
    if(A == 4)
    {
        v.push_back(2);
        v.push_back(2);
    }
    else
    {
        for (int i = 3; i < A / 2; i++) 
        {
		    if (isPrime(i) && isPrime(A - i)) 
		    {
		        v.push_back(i);
		        v.push_back(A-i);
		        break;
		    }
	    }
    }
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        cout<<*i<<endl;
    }
	return v;
}
int main(int argc, char const *argv[])
{
    vector<int> k;
    int c;
    cin>>c;
    k = primesum(c);
    // for (std::vector<int>::iterator i = k.begin(); i != k.end(); ++i)
    // {
    //     cout<<*i<<endl;
    // }
    return 0;
}