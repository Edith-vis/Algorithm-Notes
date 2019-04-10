#include <iostream>
using namespace std;

#define maxn 101
int father[maxn];

int findFather(int x) {
    if (x == father[x]) return x;

    int temp = findFather(father[x]);
    father[x] = temp;
    return temp;
}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);

    if (fa != fb) father[fa] = fb;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        Union(a, b);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (father[i] == i) cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}