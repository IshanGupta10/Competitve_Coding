#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> searchRange(const vector<int> &A, int B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	vector<int> v;
	int high,low,mid,count=0,flag=0;
	high=A.size()-1;
	low = 0;
	if(A.front()==B && A.size()==1)
	{
		v.push_back(0);
		v.push_back(0);
	}
	else if(A.front()==B && A.back()==B)
	{
		v.push_back(1);
		v.push_back(A.size());
	}
	else
	{
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
				break;
			}
		}
		cout<<"Flag "<<flag<<endl;
		cout<<"B "<<B<<endl;
		if(flag==0)
		{
			v.push_back(-1);
			v.push_back(-1);
			return v;			
		}	
		v.push_back(mid-1);
		for (int i = mid; i <A.size() ; ++i)
		{
			if(A[i]==B)
				count++;
			else
				break;
		}
		v.push_back(mid+count-1);
		count=0;
		for (int i = mid-1; i >=0 ; i--)
		{
			if(A[i]==B)
				count++;
			else
				break;
		}
		v.front()=mid-count;
		// cout<<"Front "<<v.front();
		if(v.front()==0)
		    v.front()=-1;
		if(A.front()==B)
			v.front()=0;
		// cout<<"Front "<<v.front();
	}
	return v;
}
int main(int argc, char const *argv[])
{
	int n,t;
	vector<int> k,x;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		k.push_back(t);
	}
	cout<<"Element range ";
	cin>>n;
	x = searchRange(k,n);
	for (std::vector<int>::iterator i = x.begin(); i != x.end(); ++i)
	{
		cout<<*i<<" ";
	}
	return 0;
}