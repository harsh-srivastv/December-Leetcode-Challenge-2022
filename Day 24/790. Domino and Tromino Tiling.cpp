// https://leetcode.com/problems/domino-and-tromino-tiling/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long mod = 1e9+7;
    int numTilings(int n) {
    vector<int>dp(1001,-1);
    dp[0] =1,dp[1]=1,dp[2]=2;
     for(int i=3;i<=n;i++)
     {
         dp[i] = (2*dp[i-1]%mod + dp[i-3]%mod)%mod;
     }
     return dp[n];
    }
};