#include <iostream>
#include <cstring>
using namespace std;

void strrev(char *p)
{
  char *q = p;
  while(q && *q) ++q;
  for(--q; p < q; ++p, --q)
    *p = *p ^ *q,
    *q = *p ^ *q,
    *p = *p ^ *q;
}
string convertToTitle(int n) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    char str[20];
    int i = 0;
    while (n>0)
    {
        int rem = n%26;
        if (rem==0)
        {
            str[i++] = 'Z';
            n = (n/26)-1;
        }
        else
        {
            str[i++] = (rem-1) + 'A';
            n = n/26;
        }
    }
    str[i] = '\0';
    strrev(str);
    return str;
}

int main(int argc, char const *argv[])
{
    string s;
    int t;
    cin>>t;
    s=convertToTitle(t);
    cout<<s;
    return 0;
}