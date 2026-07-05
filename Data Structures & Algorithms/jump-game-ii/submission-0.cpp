class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jump=0;
        int l=0, r=0;
        while(r<n-1){
            int maxm=0;
            for(int i=l;i<=r;i++){
                maxm = max(maxm,i+nums[i]);
            }
            l = r+1;
            r = maxm;
            jump++;
        }
        return jump;
    }
};
