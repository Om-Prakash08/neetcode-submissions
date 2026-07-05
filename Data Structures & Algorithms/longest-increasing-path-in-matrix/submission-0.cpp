class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    int solve(int x, int y, int m, int n,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        if(dp[x][y]!=-1)
         return dp[x][y];
        int temp = 0;
        for(int k=0;k<4;k++){
                int x_=x+dx[k];
                int y_=y+dy[k];
                if(x_>=0&&x_<m&&y_>=0&&y_<n&&matrix[x_][y_]<matrix[x][y]){
                    temp = max(temp,solve(x_,y_,m,n,matrix,dp));
                }
        }
        return dp[x][y] = temp+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=1;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
         for(int j=0;j<n;j++){
            int temp = 0;
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0&&x<m&&y>=0&&y<n&&matrix[x][y]<matrix[i][j]){
                    temp = max(temp,solve(x,y,m,n,matrix,dp));
                }
            }
            dp[i][j] = temp+1;
            ans = max(ans,dp[i][j]);
         }
        return ans;
    }
};
