class Solution {
public:
    bool isValid(vector<int>&freq, int k){
        int big = 0;
        int sum = 0;
        for(int i=0;i<26;i++){
            sum += freq[i];
            big = max(big,freq[i]);
        }
        return sum-big<=k;
    }
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int i = 0;
        int ans = 0;
        for(int j=i; j<s.size(); j++){
            freq[s[j]-'A']++;
            while(!isValid(freq,k)){
                freq[s[i++]-'A']--;
            }
            ans = max(ans,j-i+1);
        } 
        return ans;
    }
};
