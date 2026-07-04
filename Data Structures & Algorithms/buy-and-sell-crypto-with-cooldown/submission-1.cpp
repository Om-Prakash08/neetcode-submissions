class Solution {
public:
    int solve(int idx, int canBuy, int n, vector<int>&prices, vector<vector<int>>&dp){
        if(idx>=n)
         return 0;
        if(dp[idx][canBuy]!=-1)
         return dp[idx][canBuy];
        if(canBuy){
            return dp[idx][canBuy] = max(-prices[idx]+solve(idx+1,0,n,prices,dp),solve(idx+1,1,n,prices,dp));
        }
        return dp[idx][canBuy] = max(prices[idx]+solve(idx+2,1,n,prices,dp),solve(idx+1,0,n,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,n,prices,dp);
    }
};
