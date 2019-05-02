- 求最短距离
```c++
//1. 伪代码
Dijkstra(G, d[], s) {
    初始化;
    for (循环n次) {
        u = 使d[u]最小的还未被访问的顶点的标号;
        记u已被访问;
        for (从u出发能到达的所有顶点v) {
            if (v未被访问 && 以u为中介点使s到顶点v的最短距离d[v]更优) {
                优化d[v];
            }
        }
    }
}

//2. 邻接矩阵版
#include <vector>
using namespace std;
#define MAXV 1010
#define INF 0x3fffffff
int G[MAXV][MAXV];
int n;
bool vis[MAXV] = {false};
int d[MAXV];//起点到各点的最短距离

void Dijkstra(int s) {//起点s
    //初始化
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
            if (G[u][v] != INF && vis[v] == false && d[u]+G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];//优化d[v]
            }
        }
    }
}

//3. 邻接表版
struct Node{
    int v;//边的终点
    int dis;//边权
};

vector<Node> Adj[MAXV];
bool vis[MAXV] = {false};
int n;
int d[MAXV];

void Dijkstra(int s) {//s为源点
    fill(d, d+MAXV, INF);
    
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (d[j] < MIN && vis[j] == false) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v;
            if (vis[v] == false && d[u] + Adj[u][v].dis < d[v]) {
                d[v] = d[u] + Adj[u][v].dis;
            }
        }
    }
}
```
- 求最短路径
```c++
int n, G[MAXV][MAXV];
bool vis[MAXV] = {false};
int pre[MAXV];
int d[MAXV];

void Dijkstra(int s) {//顺道儿求出最短路径上每个点的前驱
    fill(d, d+MAXV, INF);

    d[s] = 0;
    for (int i = 0; i < n; i++) pre[i] = i;

    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < d[u]) {
                u = j;
                MIN = d[j];
            }
        }

        if (u == -1) return;
        vis[u] = true;

        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
                pre[v] = u;
            }
        }
    }
}

//递归
void DFS(int s, int v) {//s是路径起点的编号，v为当前访问的顶点编号(从终点开始递归)
    if (v == s) {//如果到达起点s，则输出起点并返回
        printf("%d\n", s);
        return;
    }

    DFS(s, pre[v]);//递归访问v的前驱顶点pre[v]
    printf("%d\n", v);//从最深处return回来之后，输出每一层的顶点号

}
```
- 有两条及以上可达到最短距离的路径
    - 新增边权:给每条边再增加一个边权 
        ```c++
        int cost[MAXV][MAXV];//新增边权表示花费 cost[u][v]表示u->v的花费
        int c[MAXV];//记录当前从起点s到顶点u的最少花费为从c[u],初始化时c[s]=0,其他为INF

        //在同为最短距离的情况下 选择最少花费
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    c[v] = c[u] + cost[u][v];
                } else if (d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]) {
                    c[v] = c[u] + cost[u][v];//最短距离相同时，看能否使c[v]更优
                } 
            }
        }
        ```
    - 新增点权:给每个点增加点权
        ```c++
        int weight[MAXV];//weight[u]代表城市u中的物资
        int w[MAXV];//w[u]为从起点s到达顶点u所能收集到的最大物资，初始化时w[s] = weight[s]其余为INF
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[v];
                } else if (d[u] + G[u][v] == d[v] && w[u] + weight[v] > w[v]) {
                    w[v] = w[u] + weight[v];//最短距离相同时，看能否使w[v]更优
                }
            }
        }
        ```
    - 求最短路径条数
        ```c++
        int num[MAXV];//num[u]表示从起点s到顶点u的最短路径个数 初始化时num[s] = 1,其余为0
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    num[v] = num[u];
                } else if (d[u] + G[u][v] == d[v]) {
                    num[v] += num[u];
                }
            }
        }
        ```
- 通用模板 Dijkstra + DFS  
    先在Dijkstra算法中记录下所有最短路径(只考虑距离)，然后从这些最短路径中选出一条第二标尺最优的路径 
    1. 使用Dijkstra算法记录所有最短路径
        ```c++
        vector<int> pre[MAXV];//对每个结点v来说，pre[v]是一个变长数组vector，里面用来存放结点v的所有能产生最短路径的前驱结点
        void Dijkstra(int s) {//s为起点
            fill(d, d+MAXV, INF);
            d[s] = 0;
            for (int i = 0; i < n; i++) {
                int u = -1, MIN = INF;
                for (int j = 0; j < n; j++) {
                    if (vis[j] ==  false && d[j] < MIN) {
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
        ```
    2. 遍历所有最短路径，找出一条使得第二标尺最优的路径
        ```c++
        int optvalue;//作为全局变量的第二标尺最优值
        vector<int> path;//记录最优路径的数组
        vector<int> tempPath;//临时记录DFS遍历到叶子结点时的路径
        //tempPath中的路径结点是逆序的，因此访问结点需要倒着进行，但如果仅是对边权或点权进行求和，那么正序访问也是可以的
        vector<int> pre[MAXV];//存放结点的先驱结点

        void DFS(int v) {//v:当前访问结点
            //递归边界
            if (v == s) {
                tempPath.push_back(v);//叶子结点无法通过递归式直接加入临时路径，因此需要在访问到叶子结点时临时加入
                int value;
                计算路径tempPath上的value值;
                if (value优于optValue) {
                    optValue = value;
                    path = tempPath;
                }
                tempPath.pop_back();
                return;
            }

            //递归式
            tempPath.push_back(v);
            for (int i = 0; i < pre[v].size(); i++) {
                DFS(pre[v][i]);
            }
            tempPath.pop_back();
        }
        ```