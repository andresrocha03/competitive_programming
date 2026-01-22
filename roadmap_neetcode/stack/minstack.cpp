//Problem: Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//Solution: Use an auxiliary stack to keep track of the minimums.

class MinStack {
private:
    stack<int> minStack;
    stack<int> otherstack;

public:

    MinStack() {}
    
    void push(int val) {
        otherstack.push(val);
        if (minStack.empty()) minStack.push(val);
        else {
            minStack.push(min(val, minStack.top()));
        }
    }
    
    void pop() {
        minStack.pop();
        otherstack.pop();
    }
    
    int top() {
        return otherstack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
