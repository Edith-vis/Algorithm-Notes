#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 1010;

int n, m, k;
int currentPoint;

vector<int> G[maxn];

int father[maxn];
bool vis[maxn];

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
    if (fa != fb) {
        father[fa] = fb;
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        vis[i] = false;
    }
}


int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int v, w;
        scanf("%d%d", &v, &w);
        G[v].push_back(w);
        G[w].push_back(v);
    }

    for (int query = 0; query < k; query++) {
        scanf("%d", &currentPoint);
        init();
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < G[i].size(); j++) {
                int v = i, w = G[i][j];
                if (v == currentPoint || w == currentPoint) continue;
                Union(v, w);
            }
        }

        int block = 0;
        for (int i = 1; i <= n; i++) {
            if (i == currentPoint) continue;
            int father_i = findFather(i);
            if (vis[father_i] == false) {
                block++;
                vis[father_i] = true;
            }
        }
        printf("%d\n", block-1);
    }

    return 0;
}