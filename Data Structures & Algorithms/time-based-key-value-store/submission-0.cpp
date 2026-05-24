class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(mp.find(key)==mp.end()){
            vector<pair<int,string>>a;
            a.push_back({timestamp,value});
            mp[key] = a;
        }
        else{
            mp[key].push_back({timestamp,value});
        }
    }
    
    string get(string key, int timestamp) {
        string ans="";
        if(mp.find(key)==mp.end())
          return ans;
        vector<pair<int,string>>a = mp[key];
        int l=0, r= a.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(a[mid].first<=timestamp)
             {
                ans = a[mid].second;
                l = mid + 1;
             }
            else
              r = mid - 1;
        }
        return ans;
    }
};
