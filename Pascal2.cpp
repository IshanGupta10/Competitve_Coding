#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generate(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int> > v;
    int i,j,o;
    for(i=0;i<A;i++)
    {
    	vector<int> row;
    	v.push_back(row);
    }
    if(A==1)
    {
    	v[0].push_back(1);
    }
    else if (A==2)
    {
		v[0].push_back(1);
		v[1].push_back(1);
		v[1].push_back(1);
    }
    else if(A > 2)
    {
		v[0].push_back(1);
		v[1].push_back(1);
		v[1].push_back(1);
    	for (i = 2; i < A; ++i)
    	{
    		for (j = 0; j <= i; ++j)
    		{
    			if(j==0)
    				v[i].push_back(1);
    			else if(j==i)
    				v[i].push_back(1);
    			else
    			{
    				o=v[i-1][j]+v[i-1][j-1];
    				v[i].push_back(o);
    			}
    		}
    	}
	}
	return v;
}

int main()
{
	vector<vector<int> > k;
	int n,c,i,j;
	//n=2;
	//cout<<n;
	cin>>n;
	//cout<<n;
	for(i=0; i < n;i++)
    {
    	vector<int> row;
    	k.push_back(row);
    }
	k=generate(n);
	for (i = 0; i < n; ++i)
	{
		c=k[i].size();
		for (j = 0; j < c; ++j)
		{
			cout<<k[i][j]<<" ";
		}
	    cout<<'\n';
	//	cout<<']'<<" ";
	}
	return 0;
}