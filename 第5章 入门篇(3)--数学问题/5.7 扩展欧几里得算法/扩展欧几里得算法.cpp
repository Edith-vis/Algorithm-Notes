#include <iostream>
using namespace std;

int exGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = exGCD(a, b, x, y);
    int oldx = x, oldy = y;
    x = oldy;
    y = oldx - a/b*oldy;
    return g;
}