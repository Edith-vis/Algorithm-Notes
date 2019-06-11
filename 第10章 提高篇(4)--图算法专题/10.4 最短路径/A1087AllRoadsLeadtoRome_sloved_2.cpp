#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define INF 0x3fffffff
#define maxn 220
int n, k;
map<string, int> cityToIndex;
map<int, string> indexToCity;
int weight[maxn];
int G[maxn][maxn];

bool vis[maxn];
int d[maxn];
vector<int> pre[maxn];
void Dijkstra(int st) {
    fill(d, d + maxn, INF);
    memset(vis, false, sizeof(vis));

    d[st] = 0;
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
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int numPath = 0, maxW = 0;
double maxAvgW = 0;
vector<int> tempPath, path;
void DFS(int v) {
    if (v == 0) {
        numPath++;
        tempPath.push_back(v);
        int size = tempPath.size();
        int totalWeight = 0;
        for (int i = 0; i < size; i++) {
            totalWeight += weight[tempPath[i]];
        }
        double avgW = 1.0 * totalWeight / (size - 1);
        if (totalWeight > maxW) {
            maxW = totalWeight;
            maxAvgW = avgW;
            path = tempPath;
        } else if (totalWeight == maxW) {
            if (avgW > maxAvgW) {
                maxAvgW = avgW;
                path = tempPath;
            }
        }
        tempPath.pop_back();
        return;
    }

    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
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
    //printf("%d %d %d %.0f\n", num[id], d[id], w[id], 1.0*w[id]/pt[id]);
    DFS(id);
    printf("%d %d %d %.0f\n", numPath, d[id], maxW, maxAvgW);
    for (int i = path.size() - 1; i >= 0; i--) {
        if (i != path.size()-1) printf("->");
        cout << indexToCity[path[i]];
    }
        return 0;
}