class Solution {
public:
    int solve(int idx, int n, int type, int price,vector<int>& prices,vector<int>&dpbuy,vector<vector<int>>&dpsell){
        if(type==1){
        if(idx>=n)
         return INT_MIN;
        if(dpsell[idx][price]!=-1)
         return dpsell[idx][price];
        return dpsell[idx][price] = max(solve(idx+1,n,1,price,prices,dpbuy,dpsell),prices[idx]-price+solve(idx+2,n,0,0,prices,dpbuy,dpsell)); 
        }
        if(idx>=n)
         return 0;
        if(dpbuy[idx]!=-1)
         return dpbuy[idx];
        return dpbuy[idx] = max(solve(idx+1,n,1,prices[idx],prices,dpbuy,dpsell),solve(idx+1,n,0,0,prices,dpbuy,dpsell)); 
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<int>dpbuy(n,-1);
        vector<vector<int>>dpsell(n,vector<int>(1001,-1));
        return solve(0,n,0,0,prices,dpbuy,dpsell);
    }
};
