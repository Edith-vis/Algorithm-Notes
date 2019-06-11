#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 1020
#define INF 0x3fffffff
int n, m, k, ds;
int G[maxn][maxn];

int d[maxn];
bool vis[maxn];
void Dijkstra(int s) {
    memset(vis, false, sizeof(vis));
    fill(d, d + maxn, INF);
    d[s] = 0;

    for (int i = 0; i < n + m; i++) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n + m; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 1; v <= n + m; v++) {
            if (G[u][v] != INF && vis[v] == false) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                }
            }
        }
    }
}

int getID(char str[]) {
    int id = 0, len = strlen(str);
    int i = 0;
    while (i < len) {
        if (str[i] != 'G') {
            id = id * 10 + (str[i]-'0');
        }
        i++;
    }
    if (str[0] == 'G') {
        id += n;
    }
    return id;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    fill(G[0], G[0] + maxn * maxn, INF);
    char c1[5], c2[5];
    int dist;
    for (int i = 0; i < k; i++) {
        scanf("%s %s %d", c1, c2, &dist);
        int id1 = getID(c1);
        int id2 = getID(c2);
        //printf("id1=%d id2=%d\n", id1, id2);
        G[id1][id2] = G[id2][id1] = dist;
    }

    double ansDis = -1, ansAvg = INF;
    int ansID = -1;
    for (int i = n + 1; i <= n + m; i++) {
        double minDis = INF, avg = 0;
        Dijkstra(i);
        for (int j = 1; j <= n; j++) {
            if (d[j] > ds) {
                minDis = -1;
                break;
            }
            if (d[j] < minDis)
                minDis = d[j];
            avg += 1.0 * d[j]/n;
        }

        if (minDis == -1)
            continue;
        if (minDis > ansDis) {
            ansID = i;
            ansDis = minDis;
            ansAvg = avg;
        } else if (minDis == ansDis && avg < ansAvg) {
            ansID = i;
            ansAvg = avg;
        }
    }

    if (ansID == -1) printf("No Solution\n");
    else {
        printf("G%d\n", ansID - n);
        printf("%.1f %.1f\n", ansDis, ansAvg);
    }

    return 0;
}