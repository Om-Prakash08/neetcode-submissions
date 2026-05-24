class Solution {
public:
    bool isAnagram(string s, string t) {
         vector<int>a(26,0);
         vector<int>b(26,0);
         for(char i: s){
            a[i-'a']++;
         }
         for(char i:t){
            b[i-'a']++;
         }
         for(int i=0;i<26;i++){
            if(a[i]!=b[i])
              return false;
         }
         return true;
    }
};
