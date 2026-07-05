class Solution {
public:
    bool overlap(pair<int,int>& a, pair<int,int>& b){
        if(a.second>=b.first)
          return true;
        return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        vector<pair<int,int>>arr;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            arr.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(arr.begin(),arr.end());
        pair<int,int>last = arr[0];
        for(int i=1;i<n;i++){
            pair<int,int>curr = arr[i];
            if(overlap(last,curr)){
              last.first = min(last.first,curr.first);
              last.second = max(last.second,curr.second);
            }else{
              ans.push_back({last.first,last.second});
              last = curr;
            }
        }
        ans.push_back({last.first,last.second});
        return ans;
    }
};
