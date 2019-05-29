#include <iostream>
using namespace std;

struct node {
    long long up, down;
};

long long gcd (long long a, long long b) {
    return b == 0 ? a : gcd(b, a%b);
}

node reduction(node a) {
    if (a.down < 0) {
        a.down = -a.down;
        a.up = -a.up;
    }

    if (a.up == 0) {
        a.down = 1;
    } else {
        long long _gcd = gcd(abs(a.up), abs(a.down));
        a.up /= _gcd;
        a.down /= _gcd;
    }
    
    return a;
}

node add(node a, node b) {
    node temp;
    temp.down = a.down*b.down;
    temp.up = a.up*b.down+b.up*a.down;
    return reduction(temp);
}

void show(node a) {
    a = reduction(a);
    if (a.down == 1) {
        printf("%lld\n", a.up);
    } else if(abs(a.up) > abs(a.down)) {
        printf("%lld %lld/%lld\n", (long long)(a.up / a.down), abs((long long)(a.up % a.down)), a.down);
    } else {
        printf("%lld/%lld\n", a.up, a.down);
    }
}



int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    node temp, ans;
    ans.up = 0, ans.down = 1;
    for (int i = 0; i < n; i++) {
        scanf("%lld/%lld", &temp.up, &temp.down);
        ans = add(ans, temp);
    }

    show(ans);

    return 0;
}