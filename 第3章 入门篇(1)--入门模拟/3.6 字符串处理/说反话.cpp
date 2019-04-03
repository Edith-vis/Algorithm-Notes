#include <cstdio>

int main() {
    freopen("D:/in.txt", "r", stdin);
    char ans[90][90];
    int cnt = 0;
    while (scanf("%s", ans[cnt]) != EOF) {
        cnt++;
    }

    for (int i = cnt-1; i >= 0; i--) {
        if (i != cnt-1) printf(" ");
        printf("%s", ans[i]);
    }
    return 0;
}