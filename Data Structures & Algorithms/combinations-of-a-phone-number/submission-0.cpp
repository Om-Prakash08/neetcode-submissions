class Solution {
public:
    void find(string &digits, int index, vector<string>&ans, string&temp, vector<string>&mappings){
        if(index==digits.size()){
            if(temp.size())
              ans.push_back(temp);
            return;
        }
        for(char c: mappings[(int)(digits[index]-'2')]){
            temp.push_back(c);
            find(digits,index+1,ans,temp,mappings);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string temp;
        vector<string>mappings(8);
        mappings[0]="abc";
        mappings[1]="def";
        mappings[2]="ghi";
        mappings[3]="jkl";
        mappings[4]="mno";
        mappings[5]="pqrs";
        mappings[6]="tuv";
        mappings[7]="wxyz";
        find(digits,0,ans,temp,mappings);
        return ans;
    }
};
