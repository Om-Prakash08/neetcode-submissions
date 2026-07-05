class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int n = nums.size();
        int last = nums[0];
        for(int i=1;i<n;i++)
         {
            int curr = max(nums[i],nums[i]+last);
            ans = max(ans,curr);
            last = curr;
         }
        return ans;
    }
};
