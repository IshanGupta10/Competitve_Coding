#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, t, min, total = 1;
    vector<int> v;

    cin>>n;

    for (int i = 0; i < n; ++i)
    {
        cin>>t;
        v.push_back(t);
    }

    t = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        if(v[i + 1] > v[i])
            t++;
    }

    min = v[0];

    for (int i = 1; i < n; ++i)
    {
        if(v[i] >= min)
        {
            min = v[i];
//            cout<<"min "<<min<<'\n';
            total++;
//            cout<<"total "<<total<<'\n';
        }
    }

    if(min == v[0])
        cout<<0<<'\n';
    else if(t == n-1)
        cout<<n<<'\n';
    else
        cout<<total<<'\n';

    return 0;
}