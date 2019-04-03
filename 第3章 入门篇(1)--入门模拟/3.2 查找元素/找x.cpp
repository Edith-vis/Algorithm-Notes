#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF) {
        int a[201];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int x;
        scanf("%d", &x);
        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                printf("%d\n", i);
                return 0;
            }
        }
        printf("-1\n");
    }
    return 0;
}