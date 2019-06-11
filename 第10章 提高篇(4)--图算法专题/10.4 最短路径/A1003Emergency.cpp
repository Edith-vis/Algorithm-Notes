#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 0x3fffffff
//基础信息
#define maxn 510
int n, m, C1, C2;
int weight[maxn];
int G[maxn][maxn];

//Dijkstra
//d[]记录最短距离，w[]记录最大点权之和，num[]记录最短路径条数
//w[u]表示从起点s到达顶点u可以得到的最大点权之和
//num[u]表示从起点s到达顶点u的最短路径条数
int d[maxn], w[maxn], num[maxn];
bool vis[maxn] = {false};

void Dijkstra(int st) {
    fill(d, d + maxn, INF);
    memset(w, 0, sizeof(w));
    memset(num, 0, sizeof(num));

    d[st] = 0;
    w[st] = weight[st];
    num[st] = 1;

    for (int i = 0; i < n; i++) {//循环n次
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
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                } else if (d[u] + G[u][v] == d[v]) {
                    if (w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &C1, &C2);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    fill(G[0], G[0] + maxn * maxn, INF);
    int c1, c2, length;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &c1, &c2, &length);
        G[c1][c2] = G[c2][c1] = length;
    }

    Dijkstra(C1);
    printf("%d %d\n", num[C2], w[C2]);

    return 0;
}