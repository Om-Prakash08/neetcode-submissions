class Solution {
public:
    bool isPossible(string &s, int idx, int n, unordered_set<string>&se,vector<int>&mems,int maxLen){
        if(idx>=n)
          return true;
        if(mems[idx]!=-1)
         return mems[idx];
        string temp="";
        for(int i=idx; i<n&&i-idx+1<=maxLen; i++){
            temp+=s[i];
            if(se.find(temp)!=se.end()&&isPossible(s,i+1,n,se,mems,maxLen)){
              mems[idx]=1;
              return true;
            }
        }
        mems[idx]=0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string>se;
        int maxLen=0;
        for(string &a: wordDict ){
            se.insert(a);
            maxLen = max(maxLen,(int)a.size());
        }
        vector<int>mems(n,-1);
        return isPossible(s,0,n,se,mems,maxLen);
    }
};
