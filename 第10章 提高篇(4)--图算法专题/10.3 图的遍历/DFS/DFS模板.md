```c++
#include <iostream>
#include <vector>
using namespace std;

void DFS(结点u) {
    vis[u] = true;

    for (从u出发能到达的所有顶点v) {
        if (vis[v] == false) {
            DFS(v);
        }
    }
}

void DFSTrave(G) {//遍历图G
    for (G的所有顶点u) {
        if (vis[u] == false) {
            DFS(u);
        }
    }
}


const int maxn = 1000;
const int INF = 1000000000;
//邻接矩阵版
int n, G[maxn][maxn];
bool vis[maxn] = {false};
void DFS(int u, int depth) {
    vis[u] = true;
    for (int v = 0; v < n; v++) {
        if (vis[v] == false && G[u][v] != INF) {
            DFS(v, depth+1);
        }
    }
}
void DFSTrave() {
    for (int u = 0; u < n; u++) {
        if (vis[u] == false) {
            DFS(u, 1);
        }
    }
}

//邻接表版
vector<int> Adj[maxn];
int n;
bool vis[maxn] = {false};

void DFS(int u, int depth) {
    vis[u] = true;
    for (int i = 0; i < Adj[u].size(); i++) {
        int v = Adj[u][i];
        if (vis[v] == false) {
            DFS(v, depth+1);
        }
    }
}
void DFSTrave() {
    for (int u = 0; u < n; u++) {
        if (vis[u] == false) {
            DFS(u, 1);
        }
    }
}
```