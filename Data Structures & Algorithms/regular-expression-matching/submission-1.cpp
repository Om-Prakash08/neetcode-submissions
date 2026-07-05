class Solution {
public:
    bool solve(int i, int j, int n, int m, string &s, string &p, vector<vector<int>>&dp){
        if(j==m)
         return i==n;
        if(dp[i][j]!=-1)
         return dp[i][j];
        bool firstMatch = (i<n&&(s[i]==p[j]||p[j]=='.'));
        if(j<m-1&&p[j+1]=='*')
         {
            return dp[i][j]= solve(i,j+2,n,m,s,p,dp)||(firstMatch&&solve(i+1,j,n,m,s,p,dp));
         }
        if(firstMatch){
            return dp[i][j] = solve(i+1,j+1,n,m,s,p,dp);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,m,s,p,dp);
    }
};
