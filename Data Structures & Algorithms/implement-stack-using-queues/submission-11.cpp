class MyStack {
public:
    std::queue<int> main;
    std::queue<int> temp;

    MyStack() {
    }
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        int temp = main.back(); // Save value for return
        for(int i = 0; i < (int)main.size() - 1; ++i){
            main.push(main.front());
            main.pop();
        }
        main.pop();
        return temp;
    }
    
    int top() {
        return main.back();
    }
    
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */