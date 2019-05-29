#include <iostream>
using namespace std;

struct node {
    long long up, down;
};

long long gcd(long long a, long long b) {
    return b == 0 ? a : (long long) gcd(b, a%b);
}

node reduction(node a) {
    if (a.down < 0) {
        a.down = -a.down;
        a.up = -a.up;
    }

    if (a.down == 0) {
        a.up = 0;
        a.down = 1;
    } else {
        long long _gcd = gcd(abs(a.up), abs(a.down));
        a.up /= _gcd;
        a.down /= _gcd;
    }
    return a;
}

void show(node a) {
    a = reduction(a);
    if (a.up < 0) printf("(");

    if (a.down == 1) {
        printf("%lld", a.up);
    } else if (abs(a.down) < abs(a.up)) {
        printf("%lld %lld/%lld", a.up/a.down, abs(a.up)%a.down, a.down);
    } else {
        printf("%lld/%lld", a.up, a.down);
    }

    if (a.up < 0) printf(")");
}

void _add(node a, node b) {
    node temp;
    temp.up = a.up*b.down + a.down*b.up;
    temp.down = a.down*b.down;
    temp = reduction(temp);
    show(a);
    printf(" + ");
    show(b);
    printf(" = ");
    show(temp);
    printf("\n");
}

void _minus(node a, node b) {
    node temp;
    temp.up = a.up*b.down - a.down*b.up;
    temp.down = a.down*b.down;
    temp = reduction(temp);
    show(a);
    printf(" - ");
    show(b);
    printf(" = ");
    show(temp);
    printf("\n");
}

void _multi(node a, node b) {
    node temp;
    temp.up = a.up*b.up;
    temp.down = a.down*b.down;
    temp = reduction(temp);
    show(a);
    printf(" * ");
    show(b);
    printf(" = ");
    show(temp);
    printf("\n");
}

void _divide(node a, node b) {
    node temp;
    temp.up = a.up*b.down;
    temp.down = a.down*b.up;
    temp = reduction(temp);
    show(a);
    printf(" / ");
    show(b);
    printf(" = ");
    
    if (b.up == 0) {
        printf("Inf\n");
        return;
    }
    show(temp);
    printf("\n");
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    node a, b;
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    //show(b);
    _add(a, b);
    _minus(a, b);
    _multi(a, b);
    _divide(a, b);

    return 0;
}