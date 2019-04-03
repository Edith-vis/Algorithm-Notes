#include <cstdio>

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int cnt = 0;
    while (n != 1) {
        cnt++;
        if (n%2 == 1) {
            n = (3*n+1)/2;
        } else {
            n = n/2;
        }
    }
    printf("%d\n", cnt);
    return 0;
}