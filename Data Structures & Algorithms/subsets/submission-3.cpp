class Solution {
public:
    void find(vector<int>&nums, vector<vector<int>>&ans, int index, vector<int>&temp){
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }
        find(nums,ans,index+1,temp);
        temp.push_back(nums[index]);
        find(nums,ans,index+1,temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        find(nums,ans,0,temp);
        return ans;
    }
};
