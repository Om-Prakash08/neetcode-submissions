class Solution {
   public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool check(vector<vector<char>>& board, int i, int j, string& word, int curr,
               vector<vector<bool>>& visited) {
        if (curr == word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[curr] || visited[i][j])
            return false;
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            if (check(board, i + dx[k], j + dy[k], word, curr + 1, visited)) return true;
        }
        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    if (check(board, i, j, word, 0, visited)) return true;
                }
            }
        }
        return false;
    }
};
