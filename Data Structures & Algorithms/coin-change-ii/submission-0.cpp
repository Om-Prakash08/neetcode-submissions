class Solution {
public:
    int solve(int amount, int idx, int n, vector<int>&coins, vector<vector<int>>&dp){
        if(amount==0)
         return 1;
        if(idx>=n)
         return 0;
        if(dp[idx][amount]!=-1)
         return dp[idx][amount];
        if(amount>=coins[idx])
          return dp[idx][amount]=solve(amount-coins[idx],idx,n,coins,dp)+solve(amount,idx+1,n,coins,dp);
        return dp[idx][amount]=solve(amount,idx+1,n,coins,dp);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(amount,0,n,coins,dp);
    }
};
