class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;
public:
    MinStack() {}
    
    void push(int val) {

        mainStack.push(val);
        if (!minStack.empty()) {
            val = min(val, minStack.top());
        } 
        minStack.push(val);
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
