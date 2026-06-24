class Solution {
public:
    int solve(vector<int>&nums, int index, int n, vector<int>&mem){
        if(index>=n)
          return 0;
        if(mem[index]!=-1)
          return mem[index];
        return mem[index]= max(nums[index]+solve(nums,index+2,n,mem),solve(nums,index+1,n,mem));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>mem(n+1,-1);
        return solve(nums,0,n,mem);
    }
};
