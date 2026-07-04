class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>tail;
        for(int a: nums){
            //first index where nums[idx]>=a
            auto it = lower_bound(tail.begin(),tail.end(),a);
            if(it==tail.end()){
                tail.push_back(a);
            }
            else{
                *it = a;
            }
        }
        return tail.size();
    }
    //nlog(n) time and o(n) space
};
