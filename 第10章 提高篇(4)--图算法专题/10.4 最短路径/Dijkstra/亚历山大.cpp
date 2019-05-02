#include <iostream>
#include <algorithm>
using namespace std;

#define MAXV 1010
#define INF 0x3fffffff
int G[MAXV][MAXV];
bool vis[MAXV] = {false};
int n, d[MAXV];

void Dijkstra(int s) {
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
            }
        }
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int e, s;
    scanf("%d%d%d", &n, &e, &s);
    fill(G[0], G[0] + MAXV*MAXV, INF);
    for (int i = 0; i < e; i++) {
        int start, end, dis;
        scanf("%d%d%d", &start, &end, &dis);
        G[start][end] = dis;
    }
    Dijkstra(s);
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", d[i]);
    }
    return 0;
}