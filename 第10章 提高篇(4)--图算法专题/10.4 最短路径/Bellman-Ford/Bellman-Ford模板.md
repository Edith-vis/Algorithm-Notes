- 如果图中有负环，且从源点可以到达，那么就会影响最短路径的求解
- 需要对图中的边进行V-1轮操作，每轮都遍历图中的所有边：  
  对每条边u->v，如果以u为中介点可以使d[v]
    ```c++
    for (i = 0; i < n-1; i++) {//执行n-1轮操作，其中n为顶点数
        for (each edge u->v) {//每轮操作都遍历所有边
            if (d[u] + length[u->v] < d[v]) {//如果以u为中介点可以使d[v]更小
                d[v] = d[u] + length[u->v];//松弛操作
            }
        }
    }
    ```
- 判断图中是否有从源点可达的负环  
    ```c++
    for (each edge u->v) {
        if (d[u] + length[u->v] < d[v]) {
            return false;
        }
    }

    return true;
    ```
- 使用邻接表
    ```c++
    struct Node {
        int v;//邻接边的目标顶点
        int dis;//邻接边的边权
    };
    vector<Node> Adj[MAXV];
    int n;
    int d[MAXV];

    bool Bellman(int s) {
        fill(d, d+MAXV, INF);
        d[s] = 0;
        for (int i = 0; i < n-1; i++) {
            for (int u = 0; u < n; u++) {
                for (int j = 0; j < Adj[u].size(); j++) {
                    int v = Adj[u][j].v;
                    int dis = Adj[u][j].dis;
                    if (d[u] + dis < d[v]) {
                        d[v] = d[u] + dis;
                    }
                }
            }
        }

        //判断负环
        for (int u = 0; u < n; u++) {//对每条边进行判断
            for (int j = 0; j < Adj[u].size(); j++) {
                int v = Adj[u][j].v;//邻接边的顶点
                int dis = Adj[u][j].dis;//邻接边的边权
                if (d[u] + dis < d[v]) {//如果仍然可以被松弛
                    return false;//说明图中有从源点可达的负环
                }
            }
        }
        return true;//数组d的所有值都已经达到最优
    }

    ```

- SPFA(Shortest Path Faster Algorithm)
  建立一个队列，每次将队首顶点u取出，然后对从u出发的所有边u->v进行松弛操作，  
  即判断`d[u] + length[u->v] < d[v]` 是否成立，如果成立，则用`d[u] + length[u->v]`覆盖`d[v]`，于是`d[v]`获得更优的值，此时如果v不在队列中，就把v加入队列。  
  这样操作直到队列为空(说明图中没有从源点可达的负环)，或者是某个顶点的入队次数超过V-1(说明图中存在从源点可达的负环)。
    ```c++
    queue<int> Q;
    源点s入队;
    while(队列非空) {
        取出队首元素u;
        for (u的所有邻接边u->v) {
            if (d[u] + dis < d[v]) {
                d[v] = d[u] + dis;
                if (v当前不在队列) {
                    v入队;
                    if (v入队次数大于n-1) {
                        说明有可达负环，return;
                    }
                }
            }
        }
    }
    ```
    使用邻接表模板
    ```c++
    #include <cstring>
    #include <algorithm>
    vector<Node> Adj[MAXV];
    int n;
    int d[MAXV];
    int num[MAXV];//记录顶点的入队次数
    bool inq[MAXV];//顶点是否在队列中

    bool SPFA(int s) {
        //初始化
        memset(inq, false, sizeof(inq));
        memset(num, 0, sizeof(num));
        fill(d, d+MAXV, INF);

        //源点入队
        queue<int> Q;
        Q.push(s);
        inq[s] = true;
        num[s]++;
        d[s] = 0;

        //主体
        while(!Q.empty()) {
            int u = Q.top();
            Q.pop();
            inq[u] = false;
            for (int i = 0; i < Adj[u].size(); i++) {
                int v = Adj[u][i].v;
                int dis = Adj[u][i].dis;
                if (d[u] + dis < d[v]) {
                    d[v] = d[u] + dis;
                    if (inq[v] == false) {
                        Q.push(v);
                        num[v]++;
                        inq[v] = true;
                        if (num[v] >= n) return false; //有可达负环
                    }
                } 
            }
        }

        return true;//无可达负环
    }
    ```