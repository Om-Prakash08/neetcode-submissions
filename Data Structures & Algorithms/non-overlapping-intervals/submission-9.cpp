class Solution {
public:
    bool overlap(pair<int,int>&a, pair<int,int>&b){
        return a.second>b.first;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(arr.begin(),arr.end());
        pair<int,int>last = arr[0];
        int ans=0;
        for(int i=1;i<n;i++){
            if(overlap(last,arr[i])){
                ans++;
                if(last.second>arr[i].second){
                    last = arr[i];
                }
            }else{
                last = arr[i];
            }
        }
        return ans;
    }
};
