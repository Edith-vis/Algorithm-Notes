#include <iostream>
using namespace std;

#define maxn 1000010
#define INF 0x7fffffff
int a[maxn], b[maxn];
int n, m;

int main() {
    freopen("D:/in.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    a[n] = INF, b[m] = INF;
    int mid = (n + m - 1) / 2;
    int i = 0, j = 0;
    int cnt = 0;

    while (cnt < mid) {
        if (a[i] < b[j]) i++;
        else j++;

        cnt++;
    }

    if (a[i] < b[j]) {
        printf("%d", a[i]);
    } else {
        printf("%d", b[j]);
    }


    return 0;
}