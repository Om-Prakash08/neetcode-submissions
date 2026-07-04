class Solution {
public:
    bool isPossible(string &s, int idx, int n, unordered_set<string>&se,vector<int>&mems){
        if(idx>=n)
          return true;
        if(mems[idx]!=-1)
         return mems[idx];
        string temp="";
        for(int i=idx; i<n; i++){
            temp+=s[i];
            if(se.find(temp)!=se.end()&&isPossible(s,i+1,n,se,mems)){
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
        for(string &a: wordDict ){
            se.insert(a);
        }
        vector<int>mems(n,-1);
        return isPossible(s,0,n,se,mems);
    }
};
