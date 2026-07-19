class Solution {
   public:
    int find(int a, vector<int>& parent) {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a], parent);
    }
    bool merge(int a, int b, vector<int>& parent, vector<int>& size) {
        int parent_a = find(a, parent);
        int parent_b = find(b, parent);
        if (parent_a == parent_b) return false;
        if (size[parent_a] < size[parent_b]) {
            parent[parent_a] = parent_b;
            size[parent_b] += size[parent_a];
        }
        parent[parent_b] = parent[parent_a];
        size[parent_a] += size[parent_b];
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        vector<int> size(n, 1);
        for (int i = 0; i < n; i++) {
            if (merge(edges[i][0] - 1, edges[i][1] - 1, parent, size) == false) {
                return {edges[i][0], edges[i][1]};
            }
        }
        return {-1, -1};
    }
};
