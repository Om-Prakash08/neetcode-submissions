class Solution {
public:
    char getOpening(char c){
        if(c==')')
          return '(';
        if(c=='}')
          return '{';
        return '[';
    }
    bool isValid(string s) {
        stack<char>stack;
        for(char c: s){
            if(c=='(' || c=='{' || c=='['){
                stack.push(c);
            }
            else if(stack.size()==0 || stack.top()!=getOpening(c))
              return false;
            else
              stack.pop();
        }

        return stack.empty();
    }
};
