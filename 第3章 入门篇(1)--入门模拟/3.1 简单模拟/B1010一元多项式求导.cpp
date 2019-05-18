#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define maxn 1010
int a[maxn];// a[e] = c

int main() {
    freopen("D:/in.txt", "r", stdin);
    fill(a, a+maxn, 0);//初始化数组a
    int coefficient, exponent;//系数 指数
    while (scanf("%d %d", &coefficient, &exponent) != EOF) {
        a[exponent] = coefficient;
    }

    //计算导数
    int cnt = 0;
    a[0] = 0;//零次项求导直接为0
    for (int i = 1; i < maxn; i++) {
        a[i-1] += i*a[i]; 
        a[i] = 0;
        if (a[i-1] != 0) cnt++;
    }

    //输出
    bool flag = false;
    if (cnt == 0) {
        printf("0 0");
    } else {
        for (int i = maxn; i >= 0; i--) {
            if (a[i] != 0) {
                if (flag) printf(" ");
                printf("%d %d", a[i], i);
                flag = true;
            }
        }
    }

    return 0;
}