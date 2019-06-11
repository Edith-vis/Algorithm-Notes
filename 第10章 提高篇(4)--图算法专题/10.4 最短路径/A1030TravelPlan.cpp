#include <iostream>
#include <algorithm>
using namespace std;
//the cities are numbered from 0 to N−1
#define maxn 510
#define INF 0x3fffffff
int n, m, S, D;
int G[maxn][maxn], cost[maxn][maxn];

bool vis[maxn] = {false};
int d[maxn], c[maxn], pre[maxn];
void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    fill(c, c + maxn, INF);
    for (int i = 0; i < n; i++) pre[i] = i;
    d[s] = 0;
    c[s] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)
            return;
        vis[u] = true;

        for (int v = 0; v < n; v++) {
            if (G[u][v] != INF && vis[v] == false) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                } else if (d[u] + G[u][v] == d[v]) {
                    if (c[u] + cost[u][v] < c[v]) {
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

void DFS(int v) {
    if (v == S) {
        printf("%d ", v);
        return;
    }
    DFS(pre[v]);
    printf("%d ", v);
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &S, &D);
    fill(G[0], G[0] + maxn * maxn, INF);
    fill(cost[0], cost[0] + maxn * maxn, INF);
    int c1, c2, dis, cos;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &c1, &c2, &dis, &cos);
        G[c1][c2] = G[c2][c1] = dis;
        cost[c1][c2] = cost[c2][c1] = cos;
    }

    Dijkstra(S);
    DFS(D);
    printf("%d %d", d[D], c[D]);

    return 0;
}