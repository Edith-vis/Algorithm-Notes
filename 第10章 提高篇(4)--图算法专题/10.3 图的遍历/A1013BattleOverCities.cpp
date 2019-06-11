#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 1010;

int n, m, k;
int currentPoint;

vector<int> G[maxn];
bool vis[maxn] = {false};

void DFS(int node) {
    if (node == currentPoint) return;
    vis[node] = true;
    for (int i = 0; i < G[node].size(); i++) {
        int v = G[node][i];
        if (vis[v] == false) {
            DFS(v);
        }
    }
}


int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int v, w;
        scanf("%d%d", &v, &w);
        G[v].push_back(w);
        G[w].push_back(v);
    }

    for (int query = 0; query < k; query++) {
        scanf("%d", &currentPoint);
        memset(vis, false, sizeof(vis));
        int block = 0;
        for (int i = 1; i <= n; i++) {
            if (i != currentPoint && vis[i] == false) {
                DFS(i);
                block++;
            }
        }
        printf("%d\n", block-1);
    }

    return 0;
}