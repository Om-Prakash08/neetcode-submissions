class Solution {
public:
    int countSubstrings(string s) {
        int n= s.size();
        vector<vector<bool>>mems(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
         mems[i][i]=true;
        int ans=n;
        for(int len=2;len<=n;len++){
            for(int i=0;i<n;i++){
                int j=i+len-1;
                if(j>=n)
                 continue;
                if(s[i]!=s[j])
                 continue;
                if(len==2|| mems[i+1][j-1]){
                 mems[i][j]=true;
                 ans++;
                }
            }
        }
        return ans;
    }
};
