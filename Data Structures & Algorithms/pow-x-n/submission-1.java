class Solution {
    public double myPow(double x, int n) {
        if(n<0)
         return 1/myPow(x,-1*n);
        if(n==0)
         return 1;
        double ans = myPow(x,n/2);
        return n%2==1?ans*ans*x:ans*ans;
    }
}
