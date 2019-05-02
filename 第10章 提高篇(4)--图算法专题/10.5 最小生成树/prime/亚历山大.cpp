#include <iostream>
#include <algorithm>
using namespace std;

#define MAXV 1010
#define INF 0x3fffffff
int G[MAXV][MAXV];
bool vis[MAXV] = {false};
int n, m, d[MAXV];

int prime() {
    fill(d, d+MAXV, INF);
    d[0] = 0;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < INF) {
                u = j;
                MIN = d[j];
            }
        }

        if (u == -1) return -1;
        vis[u] = true;
        ans += d[u];
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF && G[u][v] < d[v]) {
                d[v] = G[u][v];
            }
        }
    }

    return ans;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    
    scanf("%d%d", &n, &m);
    fill(G[0], G[0] + MAXV*MAXV, INF);
    for (int i = 0; i < m; i++) {
        int start, end, dis;
        scanf("%d%d%d", &start, &end, &dis);
        G[start][end] = G[end][start]= dis;
    }

    int ans = prime();
    printf("%d\n", ans);
    return 0;
}