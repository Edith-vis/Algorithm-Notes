#include <iostream>
using namespace std;

typedef long long LL;

//递归写法
LL binaryPower1(LL a, LL b, LL m) {
    if (b == 0) return 1;

    if (b&1) {
        return a*binaryPower1(a, b-1, m)%m;
    } else {
        LL temp = binaryPower1(a, b/2, m);
        return temp*temp%m;
    }
}

//迭代写法
LL binaryPower2(LL a, LL b, LL m) {
    LL ans = 1;
    while (b != 0) {
        if (b&1) {
            ans = ans*a%m;
        } else {

        }
        b >>= 1;
        a = a*a%m;
    }
    return ans;
}