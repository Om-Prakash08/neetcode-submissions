class Solution {
public:
    bool isValid(string st) {
        stack<char>s;
        for(char c: st){
            if(c=='('||c=='{'||c=='['){
                s.push(c);
            }else{
                if(s.empty())
                 return false;
                if(c==')'&&s.top()!='(')
                 return false;
                if(c=='}'&&s.top()!='{')
                 return false;
                if(c==']'&&s.top()!='[')
                 return false;
                s.pop();
            }
        }
        return s.empty();
    }
};
