class Solution {
public:
    long long  solve(vector<int>&coins, int amount, int index, vector<vector<int>>&mems){
        if(amount==0)
          return 0;
        if(index>=coins.size())
          return INT_MAX;
        if(mems[index][amount]!=-1)
         return mems[index][amount];
        if(amount<coins[index])
         return mems[index][amount]= solve(coins,amount,index+1,mems);
        return mems[index][amount]= min(solve(coins,amount-coins[index],index,mems)+1,solve(coins,amount,index+1,mems));
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>mems(n+1,vector<int>(amount+1,-1));
        int ans = solve(coins,amount,0,mems);
        return ans>=INT_MAX?-1:ans;
    }
};
