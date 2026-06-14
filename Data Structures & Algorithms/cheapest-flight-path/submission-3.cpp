class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto a: flights){
            int u = a[0];
            int v = a[1];
            int w = a[2];
            adj[u].push_back({v,w});
        }
        queue<int>q;
        vector<int>dist(n,INT_MAX);
        vector<int>temp;
        q.push(src);
        dist[src]=0;
        int level=0;
        while(q.empty()==false&&level<=k){
            int size = q.size();
            level++;
            temp = dist;
            while(size--){
                int u = q.front();
                q.pop();
                for(auto [v,w]: adj[u]){
                    if(w+dist[u]<temp[v]){
                      q.push({v});
                      temp[v] = w + dist[u];
                    }
                }
            }
            dist = temp;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
