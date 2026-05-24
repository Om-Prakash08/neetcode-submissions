class Solution {
public:
    bool isPalindrome(string s){
        for(int i=0;i<s.size()/2;i++)
          if(s[i]!=s[s.size()-i-1])
            return false;
        return true;
    }
    void find(vector<vector<string>>&ans, string &s, string curr, int index, vector<string>&temp){
         if(index==s.size()){
            if(curr!="" && isPalindrome(curr)){
                temp.push_back(curr);
                ans.push_back(temp);
                temp.pop_back();
            }
            return;
         }
         if(curr!="" && isPalindrome(curr)){
            temp.push_back(curr);
            string newCurr;
            newCurr+=s[index];
            find(ans,s,newCurr,index+1,temp);
            temp.pop_back();
            curr.push_back(s[index]);
            find(ans,s,curr,index+1,temp);
            return;
         }
         curr.push_back(s[index]);
         find(ans,s,curr,index+1,temp);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        string curr;
        find(ans,s,curr,0,temp);
        return ans;
    }
};
