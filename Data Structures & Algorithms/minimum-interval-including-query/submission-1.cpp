class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b){
        if(a[0]<b[0])
         return true;
        if(a[0]==b[0]&&a[1]<b[1])
         return true;
        return false;
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end(),compare);
        int n = queries.size();
        int m = intervals.size();
        vector<int>ans(n,-1);
        vector<pair<int,int>>q;
        for(int i=0;i<n;i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        int idx = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
           auto [query,index] = q[i]; 
           while(idx<m&&intervals[idx][0]<=query){
            pq.push({intervals[idx][1]-intervals[idx][0]+1,intervals[idx][1]});
            idx++;
           }
           while(pq.empty()==false&&pq.top().second<query){
            pq.pop();
           }
           if(pq.empty()==false)
            {
                ans[index] = pq.top().first;
            }
        }
        return ans;
    }
};
