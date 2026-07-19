class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--){
           carry+=digits[i];
           digits[i] = carry%10;
           carry /=10;
        }
        vector<int>ans;
        if(carry)
         ans.push_back(carry);
        for(int i=0;i<digits.size();i++){
         ans.push_back(digits[i]);
        }
        return ans;
    }
};
