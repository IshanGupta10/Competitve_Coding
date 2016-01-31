#include <iostream>
#include <vector>
using namespace std;

int searchMatrix(vector<vector<int> > &A, int B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int n = A.size();
	int i;
	for (i = 0; i < n-1; ++i)
	{
		if(B >= A[i][0] && B < A[i+1][0])
			break;
	}
	cout<<"i "<<i<<endl;
	int k = A[i].size();
	cout<<"k "<<k<<endl;
	int low,high,mid;
	low = 0;
	high = k-1;
	while(low <= high)
	{
		mid = (low+high)/2;
		cout<<"mid "<<mid<<endl;
		if(A[i][mid] < B)
			low = mid+1;
		//cout<<"high "<<high<<endl;
		else if(A[i][mid] > B)
			high = mid-1;
		//cout<<"low "<<low<<endl;
		else if(A[i][mid] == B)
			return 1;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	vector<vector<int> >v;
	int n,t;
	cin>>n;
	for(int i=0; i < n;i++)
    {
    	vector<int> row;
    	v.push_back(row);
    }
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n ; ++j)
    	{
    		cin>>t;
    		v[i].push_back(t);
    	}
    }
    cout<<"Element ";
    cin>>t;
    n = searchMatrix(v,t);
    cout<<n<<endl;
	return 0;
}