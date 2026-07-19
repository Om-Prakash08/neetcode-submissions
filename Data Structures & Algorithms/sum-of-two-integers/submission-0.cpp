class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int res = a^b;
            b = (a&b)<<1;
            a = res;
        }
        return a;
    }
};

