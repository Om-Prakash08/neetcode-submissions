class MinStack {
public:
    stack<int>s;
    stack<int>mins;
    MinStack() {
       s= {};
       mins={};
    }
    
    void push(int val) {
        s.push(val);
        if(mins.empty() || mins.top()>=val){
            mins.push(val);
        }
    }
    
    void pop() {
         if(mins.top()==s.top())
           mins.pop();
         s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
