class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans = 1;
        vector<int>mems(n,1);
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    mems[i] = max(mems[i],mems[j]+1);
                }
            }
            ans = max(ans,mems[i]);
        }
        return ans;
    }
};
