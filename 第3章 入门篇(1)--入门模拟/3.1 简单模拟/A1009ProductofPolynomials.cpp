#include <iostream>
using namespace std;

double a[1010], b[1010], c[2020];

int main() {
    freopen("D:/in.txt", "r", stdin);

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
        double co;
        scanf("%d %lf", &e, &co);
        b[e] = co;
        for (int j = 0; j < 1010; j++) {
            int ec = e+j;
            c[ec] += co*a[j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < 2020; i++) {
        if (c[i] != 0.0) cnt++;
    }

    printf("%d", cnt);
    for (int i = 2020-1; i >= 0; i--) {
        if (c[i] != 0) {
            printf(" %d %.1lf", i, c[i]);
        }
    }

    return 0;
}