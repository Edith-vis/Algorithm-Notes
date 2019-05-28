#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 100010

int coupons[maxn];
int products[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int nc, np;

    scanf("%d", &nc);
    for (int i = 0; i < nc; i++) {
        scanf("%d", &coupons[i]);
    }
    sort(coupons, coupons + nc);

    scanf("%d", &np);
    for (int i = 0; i < np; i++) {
        scanf("%d", &products[i]);
    }
    sort(products, products + np);

    int ans = 0;

    int i = 0, j = 0;
    while (i < nc && j < np && coupons[i] < 0 && products[j] < 0) {
        ans += coupons[i++]*products[j++];
    }

    i = nc-1, j = np-1;
    while (i >= 0 && j >= 0 && coupons[i] > 0 && products[j] > 0) {
        ans += coupons[i--]*products[j--];
    }

    printf("%d", ans);

    return 0;
}