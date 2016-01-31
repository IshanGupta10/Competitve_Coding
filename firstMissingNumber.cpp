#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int firstMissingPositive(vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int flag=0,j=0,k=0;
    int n=A.size()-1;
    for (vector<int>::iterator i = A.begin(); i != A.end(); ++i)
        {
        	if(*i<=0)
        		flag++;
        }
        if(flag==A.size())
        	return 1;
        for (int i=0; i < A.size(); ++i)
        {
        	if(A[i] <= A.size())
        	{
        		if(A[i] > 0)
        		{
        			int q = -1 * A[i];
        			A.push_back(q);
        		}
        	}
        }

        for (vector<int>::iterator i = A.begin(); i != A.end(); ++i)
        {
        	if(*i>0)
        	j++;	
        }

        for (vector<int>::iterator i = A.begin(); i != A.end(); ++i)
        {
        	if(*i<0)
        	n--;	
        }
        while(j<n)
        {
        	if(A[j]<0)
        		swap(A[j],A[n]);
        	j++;
        	n--;
        	if (A[j]>0)
        		j++;
        	if(A[n]<0)
        		n--;
        }
        for (std::vector<int>::iterator i = A.begin(); i != A.end(); ++i)
        {
        	if(*i > 0)
        	{
        		flag = *i;
        		break;
        	}
        }
        if(flag != 0)
        	return flag;
        else
        	return 0;
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
	n = firstMissingPositive(v);
	cout<<"Yo "<<n;
	return 0;
}