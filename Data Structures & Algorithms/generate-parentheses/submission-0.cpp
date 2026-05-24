class Solution {
public:
    void build(vector<string>&ans, string&curr, int open, int close, int n){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            curr +='(';
            build(ans,curr,open+1,close,n);
            curr.pop_back();
        }
        if(close<n&&open>close){
            curr+=')';
            build(ans,curr,open,close+1,n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
       vector<string>ans;
       string curr;
       int open=0;
       int close=0;
       build(ans,curr,open,close,n); 
       return ans;
    }
};
