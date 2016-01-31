#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) 
{
   return ((a > b) ? a : b);
}
int min(int a, int b) 
{
   return ((a < b) ? a : b);
}

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int m = B.size();
    if(A.size()<=0 || B.size()<=0)
        return -1;
    if(m==1 && n==1)
    	return (A[0]+B[0])/2.0;
	if(m==2 && n==2)
		return (max(A[0],B[0])+min(A[1],B[1]))/2.0;
	    
}