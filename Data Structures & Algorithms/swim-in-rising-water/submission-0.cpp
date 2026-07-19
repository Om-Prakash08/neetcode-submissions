class Solution {
public:
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>ans(n,vector<int>(n,INT_MAX));
        ans[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        while(pq.empty()==false){
            int dist = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if(dist>ans[i][j])
             continue;
            for(int k=0;k<4;k++){
              int x = i+dx[k];
              int y = j+dy[k];
              if(x<0||x>=n||y<0||y>=n)
               continue;
              if(ans[x][y]>max(grid[x][y],dist)){
                ans[x][y]=max(grid[x][y],dist);
                pq.push({ans[x][y],{x,y}});
              }  
            }
        }
        return ans[n-1][n-1];
    }
};
