//
// Created by Zhuoer LIU on 2025-12-05.
//
#include <stack>
using namespace std;

class MinStack {
    stack<int>data;
    stack<int>min;

public:
    MinStack() {

    }

    void push(int val) {
        if(min.empty()||val<=min.top()){
            data.push(val);
            min.push(val);
        }else{
            data.push(val);
            min.push(min.top());
        }
    }

    void pop() {
        data.pop();
        min.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
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