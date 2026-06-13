class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto a: times){
            adj[a[0]-1].push_back({a[1]-1,a[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,k-1});
        vector<int>dist(n,INT_MAX);
        dist[k-1]=0;
        while(pq.size()){
            auto [d,u] = pq.top();
            pq.pop();
            if(d>dist[u])
             continue;
            for(auto [v,w]: adj[u]){
                if(dist[u]+w<dist[v]){
                    dist[v] = dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        int maxTime=INT_MIN;
        for(auto a: dist){
            maxTime = max(maxTime, a);
        }
        return maxTime==INT_MAX?-1:maxTime;
    }
};
 