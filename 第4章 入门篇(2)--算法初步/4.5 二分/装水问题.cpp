#include <iostream>
#include <cmath>
using namespace std;

#define pi acos(-1.0)
#define eps 1e-5

double f(double R, double h) {
    double alpha = acos((R-h)/h);
    double S1 = alpha*R*R/2 - R*cos(alpha)*(R-h)/2;
    double S2 = pi*R*R/2;
    double r = S1/S2;
    return r;
}

double solve(double R, double r) {
    double left = 0, right = R, mid;
    while (right - left > eps) {
        mid = (left+right)/2;
        if (f(R, mid) > r) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return mid;
}
int main() {
    double R, r;
    scanf("%lf %lf", &R, &r);
    printf("%.4lf\n", solve(R, r));

    return 0;
}