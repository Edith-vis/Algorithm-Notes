#include <iostream>
using namespace std;

long long A, B, C;//long数据范围变为：-2^63~2^63-1

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &A, &B, &C);
        if (A+B > C) {
            printf("Case #%d: true", i);
        } else {
            printf("Case #%d: false", i);
        }
        if (i != n) printf("\n");
    }

    return 0;
}