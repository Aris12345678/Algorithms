#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6+5;

// calculating fibonacci numbers using memoization
// you can read more for memoization in here: https://www.geeksforgeeks.org/memoization-1d-2d-and-3d/

int dp[mxN]; // fill this with -1

int fib(int n) {
    if(dp[n] != -1) // already computed
        return dp[n];
    if(n <= 2) // base case
        return 1;
    int ans = fib(n-1)+fib(n-2); // recursion
    dp[n] = ans;
    return ans;
}

// calculating fibonacci numbers using tabulation
// you can read more for tabulation in here: https://www.geeksforgeeks.org/tabulation-vs-memoization/

int dp[mxN]; // leave it as it is

int fib(int n) {
    dp[1] = dp[2] = 1; // base case
    for(int i = 3; i <= n; i++)
        dp[i] = dp[i-1]+dp[i-2]; // recursion
    return dp[n];
}
