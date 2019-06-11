#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 0x3fffffff
#define maxn 220
int n, k;
map<string, int> cityToIndex;
map<int, string> indexToCity;
int weight[maxn];
int G[maxn][maxn];

bool vis[maxn];
int d[maxn], w[maxn], num[maxn], pt[maxn], pre[maxn];
void Dijkstra(int st) {
    fill(d, d + maxn, INF);
    memset(w, 0, sizeof(w));
    memset(num, 0, sizeof(num));
    memset(pt, 0, sizeof(pt));
    for (int i = 0; i < n; i++)
        pre[i] = i;

    d[st] = 0;
    w[st] = weight[st];
    num[st] = 1;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[v];
                    pt[v] = pt[u] + 1;
                    pre[v] = u;
                    num[v] = num[u];
                } else if (d[u] + G[u][v] == d[v]) {
                    num[v] += num[u];
                    if (w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                        pre[v] = u;
                        pt[v] = pt[u] + 1;
                    } else if (w[u] + weight[v] == w[v]) {
                        double uAvg = 1.0 * (w[u] + weight[v]) / (pt[u] + 1);
                        double vAvg = 1.0 * w[v] / pt[v];
                        if (uAvg > vAvg) {
                            pre[v] = u;
                            pt[v] = pt[u] + 1;
                        }
                    }
                }
            }
        }
    }
}

void DFS(int v) {
    if (v == 0) {
        cout << indexToCity[v];
        return;
    }

    DFS(pre[v]);
    cout << "->" << indexToCity[v];
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    string start, c1, c2;
    cin >> n >> k >> start;
    cityToIndex[start] = 0;
    indexToCity[0] = start;
    for (int i = 1; i < n; i++) {
        cin >> c1 >> weight[i];
        indexToCity[i] = c1;
        cityToIndex[c1] = i;
    }

    int cost;
    fill(G[0], G[0] + maxn * maxn, INF);
    for (int i = 0; i < k; i++) {
        cin >> c1 >> c2 >> cost;
        G[cityToIndex[c1]][cityToIndex[c2]] = cost;
        G[cityToIndex[c2]][cityToIndex[c1]] = cost;
    }

    Dijkstra(0);
    int id = cityToIndex["ROM"];
    printf("%d %d %d %.0f\n", num[id], d[id], w[id], 1.0*w[id]/pt[id]);
    DFS(id);

    return 0;
}