class compare{
    public:
    bool operator()(pair<int,int>&a, pair<int,int>&b){
        return a.first<=b.first;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        for(int i=0;i<k-1;i++){
            pq.push({nums[i],i});
        }
        for(int i=k-1;i<nums.size();i++){
            pq.push({nums[i],i});
            while(pq.top().second<i-k+1){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
