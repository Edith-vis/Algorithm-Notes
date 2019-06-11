#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 0x3fffffff
#define maxn 510
int cmax, n, sp, m;
int weight[maxn], G[maxn][maxn];

//the stations are numbered from 1 to N, and PBMC is represented by the vertex 0

int d[maxn];
bool vis[maxn];
vector<int> pre[maxn];
void Dijkstra(int st) {
    fill(d, d + maxn, INF);
    memset(vis, false, sizeof(vis));
    d[st] = 0;

    for (int i = 0; i <= n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j <= n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) break;
        vis[u] = true;
        for (int v = 0; v <= n; v++) {
            if (G[u][v] != INF && vis[v] == false) {
                if (d[u] + G[u][v] < d[v]) {
                    pre[v].clear();
                    pre[v].push_back(u);
                    d[v] = d[u] + G[u][v];
                } else if (d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int minNeed = INF, minBack = INF;
vector<int> tempPath, path;
void DFS(int v) {
    if (v == 0) {
        tempPath.push_back(v);
        int need = 0, remain = 0;
        for (int i = tempPath.size() - 1; i >= 0; i--) {
            int id = tempPath[i];
            if (weight[id] > 0) {
                remain += weight[id];
            } else {
                if (remain > abs(weight[id])) {
                    remain += weight[id];
                } else {
                    need -= (remain + weight[id]);
                    remain = 0;
                }
            }
        }

        if (need < minNeed) {
            path = tempPath;
            minNeed = need;
            minBack = remain;
        } else if (need == minNeed && remain < minBack) {
            path = tempPath;
            minBack = remain;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        weight[i] -= cmax / 2;
    }
    fill(G[0], G[0] + maxn * maxn, INF);
    int a, b, time;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &time);
        G[a][b] = G[b][a] = time;
    }
    Dijkstra(0);
    DFS(sp);
    printf("%d ", minNeed);
    for (int i = path.size() - 1; i >= 0; i--) {
        if (i != path.size()-1) printf("->");
        printf("%d", path[i]);
    }
    printf(" %d", minBack);

    return 0;
}