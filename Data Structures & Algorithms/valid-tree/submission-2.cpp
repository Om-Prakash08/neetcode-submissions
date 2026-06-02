class Solution {
   public:
    bool isCycleExist(vector<vector<int>>& adj, vector<bool>& visited, int n, int i, int parent) {
        visited[i] = true;
        for (auto a : adj[i]) {
            if (visited[a] == false) {
                if (isCycleExist(adj, visited, n, a, i)) return true;
            } else if (a != parent)
                return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        if(isCycleExist(adj, visited, n, 0, -1))
          return false;
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                return false;
            }
        }
        return true;
    }
};
