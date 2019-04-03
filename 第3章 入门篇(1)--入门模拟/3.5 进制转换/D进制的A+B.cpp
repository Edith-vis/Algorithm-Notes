#include <cstdio>

int main() {
    freopen("D:/in.txt", "r", stdin);
    int a, b, d;
    scanf("%d %d %d", &a, &b, &d);
    int num = a+b;
    int res[32];

    int cnt = 0;
    do {
        res[cnt++] = num%d;
        num/=d;
    } while (num!=0);
    
    for (int i = cnt-1; i >= 0; i--) {
        printf("%d", res[i]);
    }
    return 0;
}