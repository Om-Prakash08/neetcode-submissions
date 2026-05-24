class Solution {
public:
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    void dfs(vector<vector<char>>& board,vector<vector<bool>>& safe, int i, int j, int n, int m){
         safe[i][j]=true;
         for(int k=0;k<4;k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if(x>=0&&x<n&&y>=0&&y<m&&board[x][y]=='O'&&safe[x][y]==false)
             dfs(board,safe,x,y,n,m);
         }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>safe(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
         if(board[i][0]=='O')
          dfs(board,safe,i,0,n,m);
        for(int i=0;i<n;i++)
         if(board[i][m-1]=='O')
          dfs(board,safe,i,m-1,n,m);
        for(int j=0;j<m;j++)
         if(board[0][j]=='O')
          dfs(board,safe,0,j,n,m);
        for(int j=0;j<m;j++)
         if(board[n-1][j]=='O')
          dfs(board,safe,n-1,j,n,m);
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          if(board[i][j]=='O'&&safe[i][j]==false)
           board[i][j]='X';
    }
};
