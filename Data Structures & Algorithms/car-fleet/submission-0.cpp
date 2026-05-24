class Solution {
public:
    static bool compare(pair<int,int> &a, pair<int,int> &b){
          return a.first<b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>car;
        int n= position.size();
        for(int i=0;i<n;i++){
            car.push_back({position[i],speed[i]});
        } 
        sort(car.begin(),car.end(),compare);
        int ans = 1;
        pair<int,int>curr = car[n-1];
        for(int i=n-2;i>=0;i--){
            if(((target-car[i].first)*curr.second>(target-curr.first)*car[i].second)){
                curr = car[i];
                ans++;
            }
        }
        return ans;
    }
};
