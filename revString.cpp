#include <iostream>
#include <string>
#include <stack>
using namespace std;

string reverseString(string A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    string result="";
    stack<char> st,d;
    for(int i=0;i<A.length();i++)
        st.push(A[i]);

    // for(int i=0;i<A.length();i++)
    //     d.push(A[i]);

    // cout<<d.size()<<endl;

    // for (int i = d.size()-1; i>=0 ; --i)
    // {
    // 	cout<<"d's top "<<d.top()<<"A[i] "<<A[i]<<endl;
    // 	d.pop();
    // }

    // cout<<st.size();

    for (int i = st.size()-1; i>=0 ; --i)
        {
            char c = st.top();
    		cout<<"c "<<c<<endl;
            result.push_back(c);
            cout<<"result "<<result<<endl;
            st.pop();
        }
    //result.append('\0');
    return result;
}

int main(int argc, char const *argv[])
{
	string str = "((((([{()}[]]{{{[]}}})))))",k;
	k = reverseString(str);
	cout<<k<<'\n';
	return 0;
}