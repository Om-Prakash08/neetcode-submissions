class Solution {
public:
    int solve(vector<int>&cost, int a, vector<int>&mem){
        if(a==0|| a==1)
          return 0;
        if(mem[a]!=-1)
          return mem[a];
        return mem[a] = min(solve(cost,a-2,mem)+cost[a-2],solve(cost,a-1,mem)+cost[a-1]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>mem(n+1,-1);
        return solve(cost,n,mem);
    }
};
