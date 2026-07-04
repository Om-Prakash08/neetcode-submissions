class Solution {
public:
    int find(int i,int j, int m, int n, vector<vector<int>>&mems){
        if(i>=m||j>=n)
         return 0;
        if(i==m-1&&j==n-1)
         return 1;
        if(mems[i][j]!=-1)
         return mems[i][j];
        return mems[i][j]=find(i,j+1,m,n,mems) + find(i+1,j,m,n,mems);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>mems(m,vector<int>(n,-1));
        return find(0,0,m,n,mems);
    }
};
