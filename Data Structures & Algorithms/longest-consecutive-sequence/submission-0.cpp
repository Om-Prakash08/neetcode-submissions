class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int ans = 0;
        for(int i: nums){
           if(s.find(i-1)==s.end()){
             int j = i+1;
             int l = 1;
             while(s.find(j++)!=s.end()){
                l++;
             }
             ans = max(ans,l);
           }
        }
        return ans;
    }
};
