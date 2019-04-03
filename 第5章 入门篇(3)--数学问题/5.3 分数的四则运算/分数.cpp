#include <iostream>
using namespace std;

int gcd (int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

struct Fraction{
    int up, down;
};

//化简
Fraction reduction(Fraction frac) {
    if (frac.down < 0) {
        frac.up = - frac.up;
        frac.down = - frac.down;
    } 
    
    if (frac.up == 0) {
        frac.down = 1;
    } else {
        int d = gcd(abs(frac.up), abs(frac.down));
        frac.up /= d;
        frac.down /= d;
    }

    return frac;
}

//加法
Fraction add (Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up*f2.down + f2.up*f1.down;
    result.down = f1.down*f2.down;
    return reduction(result);
}

//减法
Fraction minu (Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up*f2.down - f1.down*f2.up;
    result.down = f1.down*f2.down;
    return reduction(result);
}

//乘法
Fraction multi(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up*f2.up;
    result.down = f1.down*f2.down;
    return reduction(result);
}

//除法
Fraction divide(Fraction f1, Fraction f2) {
    if (f2.up != 0) {
        Fraction result;
    result.up = f1.up*f2.down;
    result.down = f1.down*f2.up;
    return reduction(result);
    }
    return f2;
}

//输出
void showResult(Fraction r) {
    r = reduction(r);
    if (r.down == 1) printf("lld\n", r.up);
    else if (abs(r.up) > r.down) {
        printf("%d%d/%d\n", r.up/r.down, abs(r.up)%r.down, r.down);
    } else {
        printf("%d/%d\n", r.up, r.down);
    }
}

int main() {

}