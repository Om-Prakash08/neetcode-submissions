class Solution {
public:
    string findCommon(string&a , string&b){
        string ans="";
        int i=0,j=0;
        while(i<a.size()&&j<b.size()&&a[i]==b[i]){
            ans+=a[i];
            i++;
            j++;
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n<=1)
         return n==1? strs[0]: "";
        string commonPrefix=findCommon(strs[0],strs[1]);
        for(int i=2;i<n;i++){
            commonPrefix=findCommon(commonPrefix,strs[i]);
        }
        return commonPrefix;
    }
};