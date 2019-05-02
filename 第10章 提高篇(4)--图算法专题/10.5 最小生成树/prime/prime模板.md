```c++
Prime(G, d[]) {
    //G为图，一般设成全局变量
    //数组d为顶点与集合S的最短距离
    //默认使用0号顶点作为初始点
    初始化;
    for (循环n次) {
        u = 使d[u]最小的还未被访问的顶点的符号
        记u为已被访问;
        for (从u出发能到达的所有顶点v) {
            if (v未被访问&&以u为中介点使得v与集合S的最短距离d[v]更优) {
                将G[u][v]赋值给v与S集合的最短距离d[v];//与Dijkstra不同的地方
            }
        }
    }

}
```
- 邻接矩阵版
```c++
int n, G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = {false};

int prime() {
    fill(d, d+MAXV, INF);
    d[0] = 0;

    int ans = 0;//存放最小生成树的边权之和
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (d[j] < d[u] && vis[j] == false) {
                u = j;
                MIN = d[j];
            }
        }

        if (u == -1) return -1;
        vis[u] = true;
        ans += d[u];//将与集合S距离最小的边加入最小生成树
        for (int v = 0; v < n; v++) {
            //v未被访问过 && u能到达v && 以u为中介点可以使v离集合S更近
            if (vis[v] == false && G[u][v] != INF && G[u][v] < d[v]) {
                d[v] = G[u][v];
            }
        }
    }

    return ans;
}
```

- 邻接表版
```c++
struct Node {
    int v, dis;
};

vector<int> Adj[MAXV];
bool vis[MAXV] = {false};
int n;
int d[MAXV];

int prime() {
    fill(d, d+MAXV, INF);
    d[0] = 0;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < d[u]) {
                u = j;
                MIN = d[j];
            }
        }

        if (u == -1) return -1;
        vis[u] = true;
        ans += d[u];
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v;
            int dis = Adj[u][j].dis;
            if (vis[v] == false && dis < d[v]) {
                d[v] = dis;
            }
        }
    }
}
```