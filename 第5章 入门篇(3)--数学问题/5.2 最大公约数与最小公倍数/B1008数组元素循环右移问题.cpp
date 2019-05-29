#include <iostream>
using namespace std;

#define maxn 110
int a[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    bool flag = false;

    for (int i = n-m%n; i < n; i++) {
        if (i != n-m%n) printf(" ");
        flag = true;
        printf("%d", a[i]);
    }

    for (int i = 0; i < n-m%n; i++) {
        if (flag == true) printf(" ");
        flag = true;
        printf("%d", a[i]);
    }

    return 0;
}