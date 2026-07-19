class Solution {
public:
    void dfs(unordered_map<string,vector<string>>&mp,string src, vector<string>&ans){
         while(mp[src].size()){
            string back  = mp[src].back();
            mp[src].pop_back();
            dfs(mp,back,ans);
         }
         ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>mp;
        for(vector<string>ticket: tickets){
            mp[ticket[0]].push_back(ticket[1]);
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            sort(it->second.rbegin(),it->second.rend());
        }
        vector<string>ans;
        dfs(mp,"JFK",ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
