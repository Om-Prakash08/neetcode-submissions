class Solution {
public:
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          if(grid[i][j]==2)
           q.push({i,j});
        int time=-1;
        while(q.empty()==false){
           int size_ = q.size();
           time++;
           while(size_--){
            pair<int,int>front = q.front();
            q.pop();
            for(int k=0; k<4; k++){
                int x = front.first + dx[k];
                int y=  front.second + dy[k];
                if(x>=0&&x<n&&y>=0&&y<m&&grid[x][y]==1){
                    q.push({x,y});
                    grid[x][y]=2;
                }
            }
           }
        }
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          if(grid[i][j]==1)
           return -1;
        return time==-1? 0: time;
    }
};
