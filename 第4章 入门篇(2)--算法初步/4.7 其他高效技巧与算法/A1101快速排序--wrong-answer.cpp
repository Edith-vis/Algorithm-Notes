#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 100010

int origin[maxn], sorted[maxn], ans[maxn];
int n;

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &origin[i]);
        sorted[i] = origin[i];
    }

    sort(sorted, sorted+n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (origin[i] == sorted[i]) {
            ans[cnt++] = sorted[i];
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    

    return 0;
}