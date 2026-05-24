class Solution {
public:
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m, vector<vector<bool>>&visited){
        for(int k=0; k<4; k++){
            int x = i+dx[k];
            int y= j + dy[k];
            if(x>=0&&x<n&&y>=0&&y<m&&visited[x][y]==false&&grid[x][y]=='1'){
                visited[x][y]=true;
                dfs(grid,x,y,n,m,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]=='1'&&visited[i][j]==false){
                 ans++;
                 dfs(grid,i,j,n,m,visited);
               }
            }
        }
        return ans;
    }
};
