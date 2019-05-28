#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 100010
#define INF 0x7fffffff

int origin[maxn], leftMax[maxn], rightMin[maxn], ans[maxn];
int n;



    leftMax[0] = 0;
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i-1], origin[i-1]);
    }

    rightMin[n-1] = INF;
    for (int i = n - 2; i >= 0; i--) {
        rightMin[i] = min(rightMin[i+1], origin[i+1]);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (origin[i]int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &origin[i]);
    } > leftMax[i] && origin[i] < rightMin[i]) {
            ans[cnt++] = origin[i];
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