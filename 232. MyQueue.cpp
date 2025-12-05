//
// Created by Zhuoer LIU on 2025-12-05.
//
#include<stack>
using namespace std;

class MyQueue {
private:
    void inToOut(){
        if(out.empty()){
            while(!in.empty()){
                int val = in.top();  // 获取栈顶
                in.pop();            // 弹出
                out.push(val);       // 压入输出栈
            }
        }
    }

public:
    stack<int>in;
    stack<int>out;
    MyQueue() {

    }

    void push(int x) {
        inToOut();
        in.push(x);
    }

    int pop() {
        inToOut();
        int val = out.top();
        out.pop();
        return val;
    }

    int peek() {
        inToOut();
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
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