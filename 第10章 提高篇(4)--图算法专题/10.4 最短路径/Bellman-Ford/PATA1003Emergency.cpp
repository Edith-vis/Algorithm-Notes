#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct Node {
    int v, dis;
    Node (int _v, int _dis) : v(_v), dis(_dis) {}
};

#define MAXV 510
#define INF 0x3fffffff

int n, m, C1, C2;
int weight[MAXV];//点权 营救队个数
vector<Node> Adj[MAXV];

set<int> pre[MAXV];//前驱
int num[MAXV] = {0};//记录最短路径条数
int w[MAXV] = {0};//记录最大点权之和
int d[MAXV] = {INF};//记录最短距离

void Bellman(int s) {
    fill(d, d+MAXV, INF);
    fill(num, num+MAXV, 0);
    fill(w, w+MAXV, 0);
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;

    for (int i = 0; i < n-1; i++) {
        for (int u = 0; u < n; u++) {
            for (int j = 0; j < Adj[u].size(); j++) {
                int v = Adj[u][j].v;
                int dis = Adj[u][j].dis;
                if (d[u] + dis < d[v]) {
                    d[v] = d[u] + dis;
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];

                    pre[v].clear();
                    pre[v].insert(u);
                } else if (d[u] + dis == d[v]) {
                    if (w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                    }

                    pre[v].insert(u);

                    num[v] = 0;
                    for (set<int>::iterator it = pre[v].begin(); it != pre[v].end(); it++) {
                        num[v] += num[*it];
                    }
                }
            }
        }
    }
}


int main() {
    freopen("D:/in.txt", "r", stdin);

    scanf("%d%d%d%d", &n, &m, &C1, &C2);

    fill(weight, weight + MAXV, 0);
    for (int i = 0; i < n; i++){
        scanf("%d", &weight[i]);
    }

    for (int i = 0; i < m; i++) {
        int c1, c2, len;
        scanf("%d%d%d", &c1, &c2, &len);
        Adj[c1].push_back(Node(c2, len));
        Adj[c2].push_back(Node(c1, len));
    }

    Bellman(C1);
    printf("%d %d\n", num[C2], w[C2]);

    return 0;
}