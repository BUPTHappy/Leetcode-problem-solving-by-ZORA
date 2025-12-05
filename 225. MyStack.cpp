//
// Created by Zhuoer LIU on 2025-12-05.
//
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {

    }

    void push(int x) {
        int size = q.size(); //注意顺序，先记录push新元素前的顺序
        q.push(x); //再push
        for(int i=0;i<size;i++){
            int val = q.front(); //注意队列的队头元素是用的函数front()
            q.pop();
            q.push(val);
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
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