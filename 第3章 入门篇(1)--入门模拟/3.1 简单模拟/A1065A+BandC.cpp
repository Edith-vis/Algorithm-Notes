#include <iostream>
#include <cstring>
using namespace std;

long long a, b, c, res;

//long long的范围 [-2^63, 2^63) 左闭右开 大概是10^19 64位
int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        if (i != 1) printf("\n");
        //不能放在if里直接比较 要先存到一个新的long long res里
        res = a+b;

        if (a > 0 && b > 0 && res < 0) {//正溢出 a+b 一定会大于 c
            printf("Case #%d: true", i);
        } else if (a < 0 && b < 0 && res >= 0) {//负溢出 计算边界 
            printf("Case #%d: false", i);
        } else {
            if (res > c) {
                printf("Case #%d: true", i);
            } else {
                printf("Case #%d: false", i);
            }
        }
    }

    return 0;
}