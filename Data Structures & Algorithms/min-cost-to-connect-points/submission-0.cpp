class Solution {
public:
    vector<int>parent,size;
    int find(int a){
        if(parent[a]==a)
          return a;
        return parent[a]=find(parent[a]);
    }
    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(size[a]<size[b]){
           parent[a]=b;
           size[b]+=size[a];
           return;
        }
        parent[b] = a;
        size[a]+=size[b];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++) {
            parent[i]=i;
            size[i]=1;
        }
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
            edges.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),{i,j}});
          }
        }
        int ans=0;
        sort(edges.begin(),edges.end());
        for(auto e:edges){
            int w = e.first;
            int u = e.second.first;
            int v = e.second.second;
            if(find(u)==find(v))
             continue;
            ans+=w;
            merge(u,v);
        }
        return ans;
    }
};
