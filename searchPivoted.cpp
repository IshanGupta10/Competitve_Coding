#include <iostream>
#include <vector>
using namespace std;

int search(const vector<int> &A, int B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int low,high,mid,flag=0;
    low=0;
    high=A.size()-1;
    mid = (low+high)/2;
    cout<<"A[mid] "<<A[mid]<<endl;
    if(A[mid]>B)
    {
        if(A[0]>B)
        low=mid+1;
        else
        high = mid;  
    }
    while(low<=high)
    {
    	mid = (low+high)/2;
    	if(A[mid]<B)
    		low = mid+1;
    	cout<<"Low "<<low<<endl;
    	if(A[mid]>B)
    		high = mid-1;
    	cout<<"High "<<high<<endl;
    	if (A[mid]==B)
    	{
    		flag=1;
    		break;
    	}
    	cout<<"Mid "<<mid<<endl;
    }
    if(flag==1)
    	return mid;
    else
    	return -1;
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
	cout<<"Element to search ";
	cin>>n;
	t = search(v,n);
	cout<<t<<endl;
	return 0;
}
