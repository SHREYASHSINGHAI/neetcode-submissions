#include <stack>

class MyQueue {
private:
    std::stack<int> s1; // Used for pushing
    std::stack<int> s2; // Used for popping and peeking

public:
    MyQueue() {
        // Member variables s1 and s2 are automatically initialized.
    }
    
    void push(int x) {
        // Always push to the input stack
        s1.push(x);
    }
    
    int pop() {
        // peek() handles moving elements from s1 to s2 if needed
        int topElement = peek(); 
        s2.pop();
        return topElement;
    }
    
    int peek() {
        // If the output stack is empty, pour everything from s1 into s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        // The front of the queue is now at the top of s2
        return s2.top();
    }
    
    bool empty() {
        // The queue is empty only if BOTH stacks are empty
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */