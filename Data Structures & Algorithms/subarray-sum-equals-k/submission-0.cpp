class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        vector<int>prefixSum(n,0);
        mp[0]=1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(i!=0){
                prefixSum[i]=nums[i]+prefixSum[i-1]; 
            }
            else{
                prefixSum[i]=nums[i]; 
            }
            if(mp.find(prefixSum[i]-k)!=mp.end()){
                ans+=mp[prefixSum[i]-k];
            }
            if(mp.find(prefixSum[i])!=mp.end())
              mp[prefixSum[i]]++;
            else
              mp[prefixSum[i]]=1;
        }
        return ans;
    }
};