#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int> &A, int B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int high,low,mid=0,flag=0;
	low=0;
	high = A.size()-1;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(A[mid]>B)
			high = mid-1;
		if(A[mid]<B)
			low = mid+1;
		if(A[mid]==B)
		{
			flag=1;
			return mid++;
			break;
		}
	}    
	if(B>A.back())
	{   
	    mid++;
	cout<<"Mid1 "<<mid<<endl;
	    return mid;
	}
	cout<<"Mid2 "<<mid<<endl;
	if(flag==0)
	{	
		if(A[mid]<B && A[mid+1]>B)
			return ++mid;
		else
			return mid;
	}
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
	cout<<"Element search ";
	cin>>n;
	t = searchInsert(v,n);
	cout<<t;
	return 0;
}