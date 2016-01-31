#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

bool myfunction (int i,int j) { return (i<j); }

vector<int> wave(vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(),A.end(),myfunction);
    int temp;
    if(A.size()%2 == 0)
    {
        for (vector<int>::iterator i = A.begin(); i != A.end(); i+2)
        {
        	temp = *i;
        	*i = *(i+1);
        	*(i+1) = temp;
        }
    }
    else
    {
        for (vector<int>::iterator i = A.begin(); i != A.end()-1; i+2)
        {
    	    temp = *i;
        	*i = *(i+1);
    	    *(i+1) = temp;
        }
    }
    return A;
}

int main()
{
    vector<int> v,q;
	int n,QQ,i;
    //cin>>n;
    n=4;
    for (i = 0; i < n; ++i)
    {
        cin>>QQ;
        v.push_back(QQ);
        if(i==n-1)
        	break;
    }
    cout<<"Okay";
	q=wave(v);
	for (int i = 0; i < n; ++i)
	{
		cout<<q[i];
	}
	return 0;
}