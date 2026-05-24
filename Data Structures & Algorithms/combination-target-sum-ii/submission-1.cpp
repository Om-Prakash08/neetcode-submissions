class Solution {
public:
    void find(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>&temp, int index, int sum){
        if(sum==target)
         {
            ans.push_back(temp);
            return;
         }
        if(index>=candidates.size()|| sum>target) 
          return;
        temp.push_back(candidates[index]);
        find(candidates,target,ans,temp,index+1,sum+candidates[index]);
        temp.pop_back();
        index++;
        while(index<candidates.size()&&candidates[index]==candidates[index-1]){
          index++;
        }
        find(candidates,target,ans,temp,index,sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        find(candidates,target,ans,temp,0,0);
        return ans;
    }
};
