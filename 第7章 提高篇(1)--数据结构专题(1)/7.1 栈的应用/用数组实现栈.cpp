#include <iostream>
using namespace std;

struct stack{
    int TOP = -1;
    int st[];

    void clear() {
        TOP = -1;
    }

    int size() {
        return TOP+1;
    }

    bool empty() {
        return TOP == -1;
    }

    void push(int x) {
        st[++TOP] = x;
    }

    void pop() {
        TOP--;
    }

    int top() {
        return st[TOP];
    }
};