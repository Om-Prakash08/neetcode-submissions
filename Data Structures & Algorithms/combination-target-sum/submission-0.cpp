class Solution {
public:
    void find(vector<int>& nums, int target,vector<vector<int>>& ans,vector<int>&temp,int index,int sum){
       if(sum==target){
         ans.push_back(temp);
         return;
       }
       if(index==nums.size() || sum>target)
         return;
       find(nums,target,ans,temp,index+1,sum);
       temp.push_back(nums[index]);
       find(nums,target,ans,temp,index,sum+nums[index]);
       temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        int sum=0;
        find(nums,target,ans,temp,0,sum);
        return ans;
    }
};
