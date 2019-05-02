#include <iostream>
#include <algorithm>
using namespace std;

#define MAXV 200
#define INF 0x3fffffff
int n, m, dis[MAXV][MAXV];

void Floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    
    scanf("%d%d", &n, &m);
    fill(dis[0], dis[0] + MAXV*MAXV, INF);
    for (int i = 0; i < n; i++) dis[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int start, end, l;
        scanf("%d%d%d", &start, &end, &l);
        dis[start][end] = l;
    }
    Floyd();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}