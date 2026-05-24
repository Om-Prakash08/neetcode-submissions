class Solution {
public:
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
             if(grid[i][j]==0)
              q.push({i,j});
        }
        int level=0;
        while(q.empty()==false){
            int size_ = q.size();
            level++;
            while(size_--){
              pair<int,int> front = q.front();
              q.pop();
              for(int k=0;k<4;k++){
                int x = front.first  + dx[k];
                int y = front.second + dy[k];
                if(x<n&&x>=0&&y<m&&y>=0&&grid[x][y]==2147483647){
                    q.push({x,y});
                    grid[x][y]=level;
                }
              }
            }
        }
    }
};
