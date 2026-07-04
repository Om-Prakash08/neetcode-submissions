class Solution {
public:
    bool solve(string &s1, string &s2, string &s3, int i, int j,int n, int m, vector<vector<int>>&dp){
        if(i==n&&j==m)
         return true;
        
        if(dp[i][j]!=-1)
          return dp[i][j];

        if(i<n&&s1[i]==s3[i+j]){
           if(solve(s1,s2,s3,i+1,j,n,m,dp))
            return dp[i][j]=true;
        }
        if(j<m&&s2[j]==s3[i+j]){
           if(solve(s1,s2,s3,i,j+1,n,m,dp))
            return dp[i][j]=true;
        }
        return dp[i][j]=false;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(n+m!=s3.size())
         return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,s3,0,0,n,m,dp)  ;
    }
};
