class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>mem(n+1,-1);
        mem[0]=mem[1] = 0;
        for(int i=2;i<=n;i++){
            mem[i]= min(mem[i-2]+cost[i-2],mem[i-1]+cost[i-1]);
        }
        return mem[n];
    }
};
