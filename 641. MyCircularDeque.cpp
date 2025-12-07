//
// Created by Zhuoer LIU on 2025-12-07.
//
#include <vector>
using namespace std;

class MyCircularDeque {
public:
    vector<int> deque;
    int l,r,limit, size=0;
    MyCircularDeque(int k) {
        deque.resize(k);
        limit=k;
    }

    bool insertFront(int value) {
        if(isFull()) return false;

        if(isEmpty()){
            l=r=0;
            deque[l]=value;
            size++;
        }else{
            l=l==0?limit-1:l-1;
            deque[l]=value;
            size++;
        }
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        if(isEmpty()){
            l=r=0;
            deque[r]=value;
            size++;
        }else{
            r=r==limit-1?0:r+1;
            deque[r]=value;
            size++;
        }
        return true;
    }

    bool deleteFront() {
        if(isEmpty()){
            return false;
        }else{
            l=l==limit-1?0:l+1;
            size--;
            return true;
        }
    }

    bool deleteLast() {
        if(isEmpty()) return false;
        r=r==0?limit-1:r-1;
        size--;
        return true;
    }

    int getFront() {
        if(isEmpty()){
            return -1;
        }else{
            return deque[l];
        }
    }

    int getRear() {
        if(isEmpty()){
            return -1;
        }else{
            return deque[r];
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
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */