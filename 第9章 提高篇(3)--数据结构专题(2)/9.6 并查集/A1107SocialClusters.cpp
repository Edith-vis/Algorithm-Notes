#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int father[maxn];
int isRoot[maxn] = {0};
int course[maxn] = {0};

int findFather(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }

    return x;
}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa != fb) father[fa] = fb;
}

void init(int n) {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        isRoot[i] = 0;
    }
}

bool cmp(int a, int b) {
    return a > b;
}


int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    init(n);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d:", &k);
        for (int j = 0; j < k; j++) {
            int h;
            scanf("%d", &h);
            if (course[h] == 0) {
                course[h] = i;
            }
            Union(i, findFather(course[h]));
        }
    }

    for (int i = 1; i <= n; i++) {
        isRoot[findFather(i)]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (isRoot[i] != 0) ans++;
    }
    printf("%d\n", ans);
    sort(isRoot+1, isRoot+1+n, cmp);
    for (int i = 1; i <= ans; i++) {
        if (i != 1) printf(" ");
        printf("%d", isRoot[i]);
    }
    return 0;
}