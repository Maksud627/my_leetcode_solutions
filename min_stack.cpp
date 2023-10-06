// LC: 155 Min Stack: https://leetcode.com/problems/min-stack/
// Stack, design, medium

class MinStack {
public:
    vector<pair<int, int>> min_stack;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(min_stack.empty()) min_stack.push_back({val, val});
        else min_stack.push_back({val, min(val, min_stack.back().second)});
    }
    
    void pop() {
        min_stack.pop_back();
    }
    
    int top() {
        return min_stack.back().first;
    }
    
    int getMin() {
        return min_stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// TC: O(1), as all the operations of vector takes O(1) time
// SC: O(n), should take the size of the input vector or less sometimes