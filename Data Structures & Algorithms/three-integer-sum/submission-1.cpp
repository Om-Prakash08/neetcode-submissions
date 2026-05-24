class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i-1] == nums[i])
              continue;
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int sum = nums[j]+nums[k];
                if(sum==-nums[i]){
                    curr.push_back(nums[i]);
                    curr.push_back(nums[j]);
                    curr.push_back(nums[k]);
                    ans.push_back(curr);
                    curr.clear();
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                else if(sum>-nums[i]){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }
};
