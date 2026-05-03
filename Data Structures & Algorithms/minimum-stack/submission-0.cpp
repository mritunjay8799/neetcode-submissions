class MinStack {
public:
    stack<int>mainStack;
    stack<int>minTracker;
    MinStack() {
        
    }
    
    void push(int val) {
        if(mainStack.empty()){
            mainStack.push(val);
            minTracker.push(val);
        }
        else{
            mainStack.push(val);
            int top = minTracker.top();
            if(top > val)
                minTracker.push(val);
            else
                minTracker.push(top);
        }
    }
    
    void pop() {
        mainStack.pop();
        minTracker.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minTracker.top();
    }
};
