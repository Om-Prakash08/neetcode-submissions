class Solution {
public:
    bool isPossible(vector<string>&mat,int x, int y,int n){
        //check on top
        for(int i=0;i<x;i++)
          if(mat[i][y]=='Q')
            return false;
        //check on left diagonal
        int i=x-1,j=y-1;
        while(i>=0&&j>=0)
          if(mat[i--][j--]=='Q')
            return false;
        //check on right diagonal
        i=x-1, j=y+1;
        while(i>=0&&j<n)
          if(mat[i--][j++]=='Q')
            return false;
        return true;
    }
    void find(vector<string>&mat, int index, int n,vector<vector<string>> &ans){
        if(index==n){
            ans.push_back(mat);
            return;
        }
        for(int i=0;i<n;i++){
            if(isPossible(mat,index,i,n)){
                mat[index][i]='Q';
                find(mat,index+1,n,ans);
                mat[index][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>mat(n);
        string s;
        for(int i=0;i<n;i++)
         s+='.';
        for(int i=0;i<n;i++)
          mat[i] = s;
        find(mat,0,n,ans);
        return ans;
    }
};
