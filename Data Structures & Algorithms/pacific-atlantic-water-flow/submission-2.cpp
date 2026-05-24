class Solution {
   public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int i, int j, int n, int m) {
        ocean[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x < n && x >= 0 && y < m && y >= 0 && heights[x][y] >= heights[i][j] &&
                ocean[x][y] == false) {
                dfs(heights, ocean, x, y, n, m);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) dfs(heights, pac, i, 0, n, m);
        for (int j = 0; j < m; j++) dfs(heights, pac, 0, j, n, m);
        for (int i = 0; i < n; i++) dfs(heights, atl, i, m - 1, n, m);
        for (int j = 0; j < m; j++) dfs(heights, atl, n - 1, j, n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (pac[i][j] && atl[i][j]) ans.push_back({i, j});
        return ans;
    }
};
