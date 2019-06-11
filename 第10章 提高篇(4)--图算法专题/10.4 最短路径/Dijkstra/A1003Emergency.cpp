#include <iostream>
#include <algorithm>
using namespace std;

#define MAXV 510
#define INF 0x3fffffff

int N, M, C1, C2;
int G[MAXV][MAXV];
int weight[MAXV];//点权 营救队个数

int num[MAXV] = {0};
int w[MAXV] = {0};
int d[MAXV] = {INF};
bool vis[MAXV] = {false};

void Dijkstra(int s) {
    fill(num, num+MAXV, 0);
    fill(w, w+MAXV, 0);
    fill(d, d+MAXV, INF);
    d[s] = 0;
    num[s] = 1;
    w[s] = weight[s];
    for (int i = 0; i < N; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < N; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }

        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < N; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                } else if (d[u] + G[u][v] == d[v]) {
                    num[v] += num[u];
                    if (w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                    }
                }
            }
        }
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);

    scanf("%d%d%d%d", &N, &M, &C1, &C2);

    fill(weight, weight + MAXV, 0);
    for (int i = 0; i < N; i++){
        scanf("%d", &weight[i]);
    }

    fill(G[0], G[0]+MAXV*MAXV, INF);
    for (int i = 0; i < M; i++) {
        int c1, c2, len;
        scanf("%d%d%d", &c1, &c2, &len);
        G[c1][c2] = G[c2][c1] = len;
    }

    Dijkstra(C1);
    printf("%d %d\n", num[C2], w[C2]);

    return 0;
}