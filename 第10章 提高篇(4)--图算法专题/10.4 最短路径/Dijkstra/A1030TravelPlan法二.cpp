#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXV 510
#define INF 0x3fffffff
int n, m, vs, vd;

int G[MAXV][MAXV];
int cost[MAXV][MAXV];

bool vis[MAXV] = {false};
int d[MAXV];
vector<int> pre[MAXV];

void Dijkstra(int s) {
    fill(d, d+MAXV, INF);
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
            if (vis[v] == false && G[u][v] != INF) {
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


int minCost;
vector<int> path;
vector<int> tempPath;
void DFS(int v, int s) {//当前结点为v，起点为s
    if (v == s) {
        tempPath.push_back(v);
        int tempCost = 0;
        for (int i = tempPath.size()-1; i > 0; i--) {
            int id = tempPath[i], idNext = tempPath[i-1];
            tempCost += cost[id][idNext];
        }
        if (tempCost < minCost) {
            minCost = tempCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }

    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i], s);
    }
    tempPath.pop_back();
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    fill(G[0], G[0] + MAXV*MAXV, INF);
    fill(cost[0], cost[0] + MAXV*MAXV, 0);
    scanf("%d%d%d%d", &n, &m, &vs, &vd);
    for (int i = 0; i < m; i++) {
        int c1, c2;
        scanf("%d%d", &c1, &c2);
        scanf("%d%d", &G[c1][c2], &cost[c1][c2]);
        G[c2][c1] = G[c1][c2];
        cost[c2][c1] = cost[c1][c2];
    }
    Dijkstra(vs);

    minCost = INF;
    DFS(vd, vs);

    for (int i = path.size()-1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("%d %d\n", d[vd], minCost);
    return 0;
}