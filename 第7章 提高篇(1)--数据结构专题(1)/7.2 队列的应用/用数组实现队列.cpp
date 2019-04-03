#include <iostream>
using namespace std;

struct queue{
    int front;//指向队首元素的前一个位置
    int rear;//指向队尾元素
    int q[];

    void clear() {
        front = rear = -1;
    }

    int size() {
        return rear - front;
    }

    bool empty() {
        return front == rear;
    }

    void push(int x) {
        q[++rear] = x;
    }

    void pop() {
        front++;
    }

    int get_front() {
        return q[front+1];
    }

    int get_rear() {
        return q[rear];
    }
};