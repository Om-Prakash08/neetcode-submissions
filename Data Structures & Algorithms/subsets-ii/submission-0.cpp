class Solution {
public:
    void find(vector<int>&nums, vector<vector<int>>&ans, vector<int>&temp, int index){
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        find(nums,ans,temp,index+1);
        temp.pop_back();
        int j = index+1;
        while(j<nums.size()&&nums[j]==nums[index]){
            j++;
        }
        find(nums,ans,temp,j);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        find(nums,ans,temp,0);
        return ans;
    }
};
