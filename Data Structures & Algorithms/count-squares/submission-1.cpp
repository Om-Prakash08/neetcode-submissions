// struct pair_hash {
//     size_t operator()(const pair<int, int>& p) const {
//         return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
//     }
// };
class CountSquares {
public:
    vector<vector<int>>points;
    unordered_map<int,int>mp;
    CountSquares() {
        mp.clear();
        points.clear();
    }
    
    void add(vector<int> point) {
        points.push_back(point);
        mp[point[0]*1001+point[1]]++;
    }
    
    int count(vector<int> point) {
        int ans=0;
        for(vector<int> a: points){
            int dx = a[0]-point[0];
            int dy = a[1]-point[1];
            if(dx==0||dy==0||abs(dx)!=abs(dy))
             continue;
            int len = abs(dx);
            if(dx>0&&dy>0){
              ans+=(mp[(point[0]+len)*1001+point[1]]*mp[point[0]*1001+point[1]+len]);
            }
            if(dx<0&&dy>0){
                ans+=(mp[(point[0]-len)*1001+point[1]]*mp[point[0]*1001+point[1]+len]);
            }
            if(dx<0&&dy<0){
                ans+=(mp[(point[0]-len)*1001+point[1]]*mp[point[0]*1001+point[1]-len]);
            }
            if(dx>0&&dy<0){
                ans+=(mp[(point[0]+len)*1001+point[1]]*mp[point[0]*1001+point[1]-len]);
            }
        }
        return ans;
    }
};
