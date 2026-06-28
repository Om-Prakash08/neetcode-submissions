class Solution {
public:
    int solve(vector<int>& nums, vector<int>&mems, int index, int l, int r){
        if(index>r){
            return 0;
        }
        if(mems[index]!=-1)
         return mems[index];
        return mems[index]=max(nums[index]+solve(nums,mems,index+2,l,r),solve(nums,mems,index+1,l,r));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
          return nums[0];
        vector<int>mems(n+1,-1);
        int a = solve(nums,mems,0,0,n-2);
        for(int i=0;i<=n;i++)
          mems[i]=-1;
        int b = solve(nums,mems,1,1,n-1);
        return max(a,b);
    }
};

