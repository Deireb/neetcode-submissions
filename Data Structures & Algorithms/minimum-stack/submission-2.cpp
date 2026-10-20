class MinStack {
public:
    stack<int> stk;
    stack<int> min_value;
    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        if (!min_value.empty()){
            if(min_value.top() >= val){
                min_value.push(val);
            }
        }
        else{
            min_value.push(val);
        }
    }
    
    void pop() {
        if(!stk.empty()){
            if (!min_value.empty() && min_value.top() == stk.top()){
                min_value.pop();
            }
            stk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        if (min_value.empty()) {
            throw std::runtime_error("Stack is empty");
        }
        return min_value.top();
    }
};
