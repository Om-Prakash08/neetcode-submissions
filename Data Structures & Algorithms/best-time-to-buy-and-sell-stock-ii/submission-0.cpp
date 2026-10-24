class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0)
         return 0;
        vector<int>buy(n,-1);
        vector<int>settled(n,-1);
        buy[0] = -prices[0];
        settled[0]=0;
        for(int i=1;i<n;i++){
            buy[i] = max(settled[i-1] - prices[i],buy[i-1]);
            settled[i] = max(buy[i-1]+prices[i],settled[i-1]);
        }
        return settled[n-1];
    }
};