#include <iostream>
using namespace std;

#define eps 1e-5
#define pi acos(-1.0)

double f(double x) {
    return x*x;
}

double solve(double L, double R) {
    double left = L, right = R, mid;
    while (right - left > eps) {
        mid = (left+right)/2;
        if (f(mid) > 0) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return mid;
}

int main() {

    return 0;
}