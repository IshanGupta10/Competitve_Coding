int Solution::evalRPN(vector<string> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stack<int> st;
    string symbol = "+-*/";
    if(A.size()==0)
        return 0;
    for (int i = 0; i<A.size();i++)
    {
        string sym = A[i];
        int val =symbol.find(sym);
        if (val != -1)
        {
            if (st.size()<2)
                return -1;
            else
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (val==0)
                    st.push(b+a);
                if (val==1)
                    st.push(b-a);
                if (val==2)
                    st.push(b*a);
                if (val==3)
                    st.push(b/a);
            }
        }
        else
            st.push(atoi(sym.c_str()));
    }
    return st.top();    
}