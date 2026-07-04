class Solution {
public:
    bool isSubsetPossible(vector<int>&nums, int idx, int sum, vector<vector<int>>&mems){
        if(sum==0)
          return true;
        if(idx>=nums.size())
          return false;
        if(mems[idx][sum]!=-1)
         return mems[idx][sum];
        if(sum>=nums[idx])
         return mems[idx][sum] = isSubsetPossible(nums,idx+1,sum-nums[idx],mems) ||  isSubsetPossible(nums,idx+1,sum,mems);
        return mems[idx][sum] = isSubsetPossible(nums,idx+1,sum,mems);
      
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int a: nums){
            sum+=a;
        }
        if(sum%2)
          return false;
        vector<vector<int>>mems(nums.size(),vector<int>(sum/2+1,-1));
        return isSubsetPossible(nums,0,sum/2,mems);
    }
};
