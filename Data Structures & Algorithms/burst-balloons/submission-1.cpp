class Solution {
public:
    int solve(int l, int r, int n, vector<int>&nums, vector<vector<int>>&dp){
        if(l<=0||r>=n-1)
         return 0;
        if(dp[l][r]!=-1)
         return dp[l][r];
        int ans=0;
        for(int k=l;k<=r;k++){
           ans = max(ans,solve(l,k-1,n,nums,dp)+solve(k+1,r,n,nums,dp)+nums[k]*nums[l-1]*nums[r+1]);
        }
        return dp[l][r]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(1,n-2,n,nums,dp);
    }
};
