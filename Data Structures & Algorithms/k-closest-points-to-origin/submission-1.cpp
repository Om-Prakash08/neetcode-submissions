class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>pq;
        for(auto a: points){
            int dist = a[0]*a[0] + a[1]*a[1];
            pq.push({dist,a});
            if(pq.size()>k)
             pq.pop();
        }
        vector<vector<int>>ans;
        while(pq.empty()==false){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
