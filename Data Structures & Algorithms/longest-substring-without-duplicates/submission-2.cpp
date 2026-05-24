class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>curr_set;
        int i=0;
        int ans=0;
        for(int j=i;j<s.size();j++){
            while(curr_set.find(s[j])!=curr_set.end()){
                    curr_set.erase(s[i++]);
                }
            curr_set.insert(s[j]);
            ans = max(ans,(int)curr_set.size());
        }
        return ans;
    }
};
