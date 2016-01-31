#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Interval
{
	int start;
	int end;
};

typedef struct Interval inter;

bool compare(inter a,inter b)
{
	return (a.start < b.start);
}

vector<inter> mergeIntervals(vector<inter> &interv)
{
	if(&interv == NULL || interv.size()<=1)
		return interv;

	sort(interv.begin(),interv.end(),compare);
	inter q,merged,r; 
	q = interv.front();

	vector<inter> result;
	for (vector<inter>::iterator i = interv.begin(); i != interv.end(); ++i)
	{
		r = *i;
		if(q.end >= r.start)
		{
			merged.start = q.start;
			merged.end = fmax(q.end,r.end);
			q = merged;
		}
		else
		{
			result.push_back(q);
			q = r;
		}
	}
	result.push_back(q);
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
	t = mergeIntervals(v);
	printIntervals(t);
	v.erase(v.begin(),v.end());
	t.erase(t.begin(),t.end());
	return 0;
}