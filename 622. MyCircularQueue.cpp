//
// Created by Zhuoer LIU on 2025-12-05.
//
#include <vector>
using namespace std;

class MyCircularQueue {
public:
    //要先声明全局的变量
    vector<int> queue;
    int l,r,limit,size;

    MyCircularQueue(int k) {
        queue.resize(k); //注意这里再给queue的大小赋值
        l=0,r=0,limit=k,size=0;
    }

    bool enQueue(int value) {
        if(isFull()){
            return false;
        }else{
            queue[r]=value;
            r = r==(limit-1) ? 0 : r+1 ;
            size++;
            return true;
        }
    }

    bool deQueue() {
        if(isEmpty()){
            return false;
        }else{
            l=l==limit-1?0:l+1;
            size--;
            return true;
        }
    }

    int Front() {
        if(isEmpty()){
            return -1;
        }else{
            return queue[l];
        }
    }

    int Rear() {
        if(isEmpty()){
            return -1;
        }else{
            return queue[r==0?limit-1:r-1];
        }
    }

    bool isEmpty() {
        return size==0;
    }

    bool isFull() {
        return size==limit;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */