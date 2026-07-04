class Solution {
public:
    bool solve(string &s1, string &s2, string &s3, int i, int j, int firstOrSecond, int n, int m, vector<vector<vector<int>>>&dp){
        if(i==n&&j==m)
         return true;
        
        if(dp[i][j][firstOrSecond]!=-1)
          return dp[i][j][firstOrSecond];
        
        if(firstOrSecond==0){
           int k = i;
           while(k<n&&s1[k]==s3[k+j]){
            if(solve(s1,s2,s3,k+1,j,1,n,m,dp)){
                return dp[i][j][firstOrSecond]=true;
            }
            k++;
           }
        }
        if(firstOrSecond==1){
           int k = j;
           while(k<m&&s2[k]==s3[k+i]){
            if(solve(s1,s2,s3,i,k+1,0,n,m,dp)){
                return dp[i][j][firstOrSecond]=true;
            }
            k++;
           }
        }
        return dp[i][j][firstOrSecond]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(n+m!=s3.size())
         return false;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(2,-1)));
        return solve(s1,s2,s3,0,0,0,n,m,dp) || solve(s1,s2,s3,0,0,1,n,m,dp) ;
    }
};
