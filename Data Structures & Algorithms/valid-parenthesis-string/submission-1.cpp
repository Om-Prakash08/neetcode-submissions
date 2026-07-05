class Solution {
public:
    bool checkValidString(string s) {
        stack<int>open,star;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
             open.push(i);
            if(s[i]=='*')
             star.push(i);
            if(s[i]==')'){
                if(open.empty()==false)
                  open.pop();
                else if(star.empty()==false)
                  star.pop();
                else
                 return false;
            }
        }
        while(open.empty()==false&&star.empty()==false){
           if(open.top()>star.top())
            return false;
           open.pop();
           star.pop();
        }
        return open.empty()==true;
    }
};

  