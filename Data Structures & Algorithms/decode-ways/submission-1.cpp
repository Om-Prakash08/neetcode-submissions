class Solution {
public:
    
    int solve(string &s, int index, int n,vector<int>&mems){
        if(index==n)
          return 1;
        if(s[index]=='0')
          return 0;
        if(mems[index]!=-1)
         return mems[index];
        int ans= solve(s,index+1,n,mems);
        if(index<n-1){
            int a = (s[index]-'0')*10+(s[index+1]-'0');
            if(a>=10&&a<=26)
             ans+=solve(s,index+2,n,mems);
        }
        return mems[index]=ans;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>mems(n,-1);
        return solve(s,0,n,mems);
    }
};
