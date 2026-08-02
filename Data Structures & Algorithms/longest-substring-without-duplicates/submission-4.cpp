class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
         return 0;
        int ans =0;
        int i=0, j=0;
        unordered_set<char>hash;
        while(j<s.size()){
           while(hash.find(s[j])!=hash.end()){
            hash.erase(s[i++]);
           }
           hash.insert(s[j]);
           ans = max(ans,j-i+1);
           j++;
        }
        return ans;
    }
};
