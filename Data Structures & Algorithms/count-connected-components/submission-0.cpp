class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<bool>&visited, int i){
        visited[i] = true;
        for(auto a: adj[i]){
            if(visited[a]==false)
             dfs(adj,visited,a);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>>adj(n);
    vector<bool>visited(n,false);
    for(auto e: edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            ans++;
            dfs(adj,visited,i);
        }
    }
    return ans;
    }
};
