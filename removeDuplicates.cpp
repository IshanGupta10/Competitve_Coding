#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void removeDuplicates(vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    // if(A.size()<=1)
    //     return A.size();
    A.erase( unique( A.begin(), A.end() ), A.end() );
    //return A.size();
    // return A.size();
    for (std::vector<int>::iterator i = A.begin(); i != A.end(); ++i)
    {
        cout<<*i<<" ";
    }
}
int main(int argc, char const *argv[])
{
    vector<int> s;
    s.push_back(1);
    s.push_back(1);
    s.push_back(1);
    s.push_back(1);
    s.push_back(1);
    s.push_back(2);
    s.push_back(4);
    s.push_back(7);
    s.push_back(7);
    s.push_back(7);
    removeDuplicates(s);
    //int k=removeDuplicates(s);
    //cout<<k<<endl;
    return 0;
}