class Solution {
public:
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    void dfs(vector<vector<int>>&grid,vector<vector<bool>>&visited,int i, int j, int n, int m, int &curr){
        visited[i][j]=true;
        curr++;
        for(int k=0;k<4;k++){
            int x = i+dx[k];
            int y = j+dy[k];
            if(x<n&&x>=0&&y<m&&y>=0&&visited[x][y]==false&&grid[x][y]==1){
                dfs(grid,visited,x,y,n,m,curr);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==false&&grid[i][j]==1){
                    int curr = 0;
                    dfs(grid,visited,i,j,n,m,curr);
                    ans = max(ans,curr);
                }
            }
        }
        return ans;
    }
};
