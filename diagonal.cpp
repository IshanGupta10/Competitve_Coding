#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > diagonal(vector<vector<int> > &A)
{
    vector<vector<int> > v;
    int i,j,n,k;
    n = (2*A.size())-1;
    //cout<<"n "<<n<<'\n';
    for(i=0;i<n;i++)
    {
        vector<int> row;
        v.push_back(row);
        //cout<<i<<'\n';
    }
    if(n==1)
    {
        v[0].push_back(A[0][0]);
        //cout<<v[0][0];
    }
    else if(n > 1)
    {
        for(k=0;k<A.size();k++)
        {
            //cout<<k<<'\n';  
            for(i=0,j=k;i<=k,j>=0;i++,j--)
            {
                v[k].push_back(A[i][j]);
            //    cout<<"x "<<v[k][i]<<'\n';
            }
        }
        int q = A.size();
        //cout<<"q "<<q<<'\n';
        for(k=1;k<A.size();k++)
        {
            //int z=0;
            //cout<<"k "<<k<<'\n';
            //cout<<"q "<<q<<'\n';            
            for(i=k,j=A.size()-1;j>0,i<A.size();i++,j--)
            {
            //    cout<<"i "<<i<<"j "<<j<<endl;
            //    cout<<"test "<<A[i][j]<<endl;
                v[q].push_back(A[i][j]);
            //    int z=0;
            //  cout<<"y "<<v[q][z]<<'\n';
            //    z++;
            //    if(i==A.size() && j==A.size())
                //{
                //cout<<"y "<<v[q][0]<<'\n';    
            //        break;                
                //}
            }
            //z++;
            //if(q<n)
            q++;
        }
    }
    // for (int i = 0; i <n ; ++i)
    // {
    //     int q = v[i].size();
    //     for (int j = 0; j < q; ++j)
    //     {
    //         cout<<v[i][j];
    //     }
    //     cout<<'\n';
    // }
    return v;
}

int main()
{
    vector<vector<int> > k,t;
    int n,i,j,w;
    cin>>n;
    for(i=0;i<n;i++)
    {
        vector<int> row;
        k.push_back(row);
    }
    cout<<"rows"<<'\n';
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>w;
            k[i].push_back(w);
        }
    }
    cout<<"Entry Complete."<<'\n';    
    t = diagonal(k);
    int q = t.size();
    cout<<"DOne."<<'\n';
    for (int i = 0; i <q ; ++i)
    {
        n = t[i].size();
        for (int j = 0; j < n; ++j)
        {
            cout<<t[i][j];
        }
        cout<<'\n';
    }
}