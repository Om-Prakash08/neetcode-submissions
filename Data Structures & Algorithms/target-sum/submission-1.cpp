class Solution {
public:
    long long solve(int idx, int n, vector<int>&nums, int target, vector<vector<long long>>&dp){
        if(idx==n)
         return target==0;
        if(idx>n)
         return 0;
        if(dp[idx][target]!=-1)
         return dp[idx][target];
        if(nums[idx]<=target)
         return dp[idx][target]= solve(idx+1,n,nums,target-nums[idx],dp)+solve(idx+1,n,nums,target,dp);
        return dp[idx][target]= solve(idx+1,n,nums,target,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        long long sum = 0;
        for(int a: nums){
            sum+=(long long)a;
        }
        if(abs(target)>sum)
         return 0;
        sum +=(long long) target ;
        if(sum%2)
         return 0;
        sum  = sum/2;
        vector<vector<long long>>dp(n,vector<long long>(sum+1,-1));
        return solve(0,n,nums,sum,dp);
    }
};
