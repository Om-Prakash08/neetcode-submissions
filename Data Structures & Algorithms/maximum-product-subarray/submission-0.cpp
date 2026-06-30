class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int minm=1;
        int maxm=1;
        for(int a:nums){
            int curr_minm= min(a,min(a*minm,a*maxm));
            int curr_maxm = max(a,max(a*maxm,a*minm));
            ans = max(ans,curr_maxm);
            minm = curr_minm;
            maxm = curr_maxm;
        }
        return ans;
    }
};
