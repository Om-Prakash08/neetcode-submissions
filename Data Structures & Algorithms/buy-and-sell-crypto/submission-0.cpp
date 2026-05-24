class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int l = prices[0];
    int ans = 0;
    for(int i=1;i<prices.size();i++){
        ans = max(ans,prices[i]-l);
        l = min(l,prices[i]);
    }
    return ans;   
    }
};
