#include <iostream>
using namespace std;

#define maxn 1010
double a[maxn], b[maxn], c[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    fill(a, a+maxn, 0.0);
    fill(b, b+maxn, 0.0);
    fill(c, c+maxn, 0.0);
    int n1;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        int e;
        double c;
        scanf("%d %lf", &e, &c);
        a[e] = c;
    }

    int n2;
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        int e;
        double c;
        scanf("%d %lf", &e, &c);
        b[e] = c;
    }

    int cnt = 0;
    for (int i = 0; i < maxn; i++) {
        c[i] = a[i]+b[i];
        if (c[i] != 0.0) cnt++;
    }

    printf("%d", cnt);

    for (int i = maxn-1; i >= 0; i--) {
        if (c[i] != 0.0) {
            printf(" %d %.1lf", i, c[i]);
        }
    }


    return 0;
}