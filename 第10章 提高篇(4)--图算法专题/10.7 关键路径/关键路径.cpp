#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAXV 1010
#define INF 0x3fffffff
vector<int> Adj[MAXV];
int n, m;
int inDegree[MAXV];

bool topologicalSort() {
    int num = 0;//记录已经加入拓扑序列的结点个数
    queue<int> q;//用来存放所有入度为0的顶点

    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < Adj[u].size(); i++) {
            int v = Adj[u][i];
            inDegree[v]--;
            if (inDegree[v] == 0) q.push(v);
        }
        Adj[u].clear();
        num++;
    }

    if (num == n) return true;
    else return false;
}

int CriticalPath() {
    
}