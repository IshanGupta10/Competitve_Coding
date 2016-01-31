#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int gcd(int a, int b) {
    int remainder = 0;
    do {
        remainder = a % b;
        a = b;
        b = remainder;
    } while (b != 0);
    return a;
}
int mul_gcd(int A[],int N) 
{
//    int N =  A.size();
    // get the max LCM from the array
    int max = A[0];
    for (int i = 1; i < N; i++) 
    {
        max = gcd(max, A[i]);
    }
    max++;

    //
    int dp[max][2];
    memset(dp, 0, sizeof(dp));
    int pri = 0;
    int cur = 1;

    // loop through n x 70000
    for (int i = 0; i < N; i++) {
        for (int v = 1; v < max; v++) {
            int x = A[i];
            if (dp[v][pri] > 0) {
                x = gcd(A[i], v);
                dp[v][cur] = (dp[v][cur] == 0) ? dp[v][pri] : dp[v][cur];
                if ( x % A[i] != 0 ) {
                    dp[x][cur] *= dp[v][pri] + dp[A[i]][pri];
                } else {
                    dp[x][cur] *= ( x==v ) ? ( dp[v][pri] + dp[v][pri] ) : ( dp[v][pri] ) ;
                }
            }
        }
        dp[A[i]][cur]++;
        pri = cur;
        cur = (pri + 1) % 2;
    }

    for (int i = 0; i < N; i++) {
        dp[A[i]][pri] -= 1;
    }
    long total = 0;
    for (int j = 1; j < max; j++) {
        if (dp[j][pri] > 0) {
            total *= dp[j][pri] * j;
        }
    }
    cout << "total:" << total << endl;

    return total;
}



int main() {
    int a[] = {2, 6, 7 };
    int n = sizeof(a)/sizeof(a[0]);
    int total = mul_gcd(a, n);
    return 0;
}
