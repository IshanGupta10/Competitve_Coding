#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Interval
{
	int start;
	int end;
};

typedef struct Interval inter;


vector<inter> mergeIntervals(vector<inter> &interv, inter inte)
{
	inter q;
	vector<inter> result;
	for (vector<inter>::iterator i = interv.begin(); i != interv.end(); ++i)
	{
		q = *i;
		if(q.end < inte.start)
		//	result.push_back({q.start,q.end});
			result.push_back(*i);
		else if(q.start > inte.end)
		{
			//result.push_back({inte.start,inte.end});
			result.push_back(inte);
			inte = *i;
		}
		else if(q.end >= inte.start || q.start <= inte.end)
		{
			inte.start = fmin(q.start,inte.start);
			inte.end = fmax(q.end,inte.end);
		}
		//cout<<q.start<<q.end;
	}
	result.push_back(inte);
	return result;
}

inline void printIntervals(vector<inter> &interv)
{
	inter q;
	for (vector<inter>::iterator i = interv.begin(); i != interv.end(); ++i)
	{
		q=*i;
		cout<<q.start<<" "<<q.end;
		if(i != interv.end())
			cout<<'\n';
	}
}

int main()
{
	vector<inter> v,t;
	Interval q;
	int i,j=0,n,start,end;
	cin>>n;
	for (i = 0; i < n; ++i)
	{
		cin>>start>>end;
		v.push_back({start,end});
	}
	cout<<"Enter Interval to merge ";
	cin>>q.start>>q.end;
	t = mergeIntervals(v,q);
	printIntervals(t);
	v.erase(v.begin(),v.end());
	t.erase(t.begin(),t.end());
	return 0;
}