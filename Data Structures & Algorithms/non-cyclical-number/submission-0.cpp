class Solution {
public:
    int calculate(int n){
        int ans = 0;
        while(n){
            int a  = n%10;
            ans += (a*a);
            n /=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int>s;
        while(n!=1&&s.find(n)==s.end()){
            s.insert(n);
            n = calculate(n);
        }
        return n==1;
    }
};
