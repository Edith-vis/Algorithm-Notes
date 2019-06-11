#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//the cities are numbered from 0 to N−1
#define maxn 510
#define INF 0x3fffffff
int n, m, S, D;
int G[maxn][maxn], cost[maxn][maxn];

bool vis[maxn] = {false};
int d[maxn];
vector<int> pre[maxn];
void Dijkstra(int s) {
    fill(d, d + maxn, INF);
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
            if (G[u][v] != INF && vis[v] == false) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int minCost = INF;
vector<int> tempPath, path;
void DFS(int v) {
    //printf("%d\n", v);
    if (v == S) {
        tempPath.push_back(v);
        int totalCost = 0;
        for (int i = 0; i < tempPath.size() - 1; i++) {
            int id = tempPath[i], idNext = tempPath[i + 1];
            totalCost += cost[id][idNext];
        }
        if (totalCost < minCost) {
            minCost = totalCost;
            path = tempPath;
        }
        //printf("%d\n", totalCost);
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
    for (int i = path.size() - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("%d %d", d[D], minCost);

    return 0;
}