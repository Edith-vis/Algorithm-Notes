```c++
#include <iostream>
#include <queue>
using namespace std;

void BFS(u) {
    queue q;
    将u入队;
    inq[u] = true;
    while (!q.empty()) {
        取出q的队首元素u进行访问;
        for (从u出发所有可达的顶点v) {
            if (inq[v] == false) {
                q.push(v);
                inq[v] = true;
            }
        }
    }
}

void BFSTrave(G) {
    for (G的所有顶点u) {
        if (inq[u] == false) {
            BFS(u);
        }
    }
}

//1.邻接矩阵版
#define MAXV 1000
int n, G[MAXV][MAXV];
bool inq[MAZV] = {false};

void BFS(int u) {//遍历u所在连通块
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (G[u][v] != INF && inq[v] == false) {
                q.push(v);
                inq[v] = true;
            } 
        }
    }
}

void BFSTrave() {//遍历图G
    for (int u = 0; u < n; u++) {
        if (inq[u] == false) {
            BFS(u);
        }
    }
}

//2.邻接表版
vector<int> Adj[MAXV];
int n;
bool inq[MAXV] = {false};

void BFS(int u) {//遍历u所在连通块
    queue<int> q;
    q.push(u);
    inq[u] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < Adj[u].size(); i++) {
            int v = Adj[u][i];
            if (inq[v] == false) {
                q.push(v);
                inq[v] = true;
            }
        }
    }
}

void BFSTrave() {//遍历图G
    for (int u = 0; u < n; u++) {
        if (inq[u] == false) {
            BFS(u);
        }
    }
}

//3.在给定初始顶点的情况下，需要输出该连通块内所有其他顶点的层号
struct Node {
    int v;
    int layer;
};

vector<Node> Adj[MAXV];

void BFS(int s) {
    queue<Node> q;
    Node start;
    start.v = s;
    start.layer = 0;
    q.push(start);
    inq[start.v] = true;
    inq[s] = true;
    while (!q.empty()) {
        Node topNode = q.front();
        q.pop();
        int u = topNode.v;
        for (int i = 0; i < Adj[u].size(); i++) {
            Node next = Adj[u][i];
            next.layer = topNode.layer + 1;
            if (inq[next.v] == false) {
                q.push(next);
                inq[next.v] = true;
            }
        }
    }
}
```