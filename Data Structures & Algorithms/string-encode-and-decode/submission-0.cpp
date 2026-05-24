class Solution {
public:

    string encode(vector<string>& strs) {
       string encodedStr = "";
       for(string s: strs){
          encodedStr+=to_string(s.length());
          encodedStr+='#';
          encodedStr+=s;
       }
       return encodedStr;
    }

    vector<string> decode(string s) {
       vector<string>ans;
       int i = 0;
       while(i<s.size()){
        int len;
        string lenStr="";
        while(s[i]!='#'){
         lenStr+=s[i];
         i++;
        }
        len = stoi(lenStr);
        i++;
        string element="";
        while(len--){
            element+=s[i];
            i++;
        }
        ans.push_back(element);
       }
       return ans;
    }
};
