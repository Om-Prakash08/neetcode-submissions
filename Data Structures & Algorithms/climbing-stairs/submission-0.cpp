class Solution {
public:
    int solve(int n, vector<int>&m){
        if(m[n]!=-1)
          return m[n];
        if(n<=1)
          return 1;
        if(n==2)
          return 2;
        return m[n] = solve(n-1,m)+solve(n-2,m);
    }
    int climbStairs(int n) {
        vector<int>m(n+1,-1);
        return solve(n,m);
    }
};
