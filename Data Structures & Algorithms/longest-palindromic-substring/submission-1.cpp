class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1)
         return s;
        vector<vector<bool>>mems(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
         mems[i][i]= true;
        int maxLen=1;
        int startIdx=0;
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n;i++){
                int j=i+len-1;
                if(j>=n)
                  continue;
                if(s[i]!=s[j])
                  continue;
                if(s[i]==s[j]&&(len==2||mems[i+1][j-1])){
                    mems[i][j]=true;
                    if(maxLen<len){
                        maxLen = len;
                        startIdx = i;
                    }
                }
            }
        }
        return s.substr(startIdx,maxLen);
    }
};
  