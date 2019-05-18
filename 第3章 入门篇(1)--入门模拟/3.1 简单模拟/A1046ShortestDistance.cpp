#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
#define maxn 100010
#define INF 0x3fffffff
int node[maxn] = {0};


int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        node[i] = 0;
    }

    //node[0] = total length of the circle
    //node[1] = 0
    //node[2] = form 1 to 2
    //node[3] = from 1 to 3
    //node[4] = from 1 to 4
    //node[5] = from 1 to 5

    //dis[1, 3] = min(total, total-(node[3]-node[1]))
    int dis;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &dis);
        node[i] = dis + node[i-1];
    }
    scanf("%d", &dis);
    node[0] = dis + node[n];

    //for (int i = 0; i <= n; i++) {
    //    printf("%d ", node[i]);
    //}
    //printf("\n");

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int id1, id2;
        scanf("%d %d", &id1, &id2);
        if (i != 0) printf("\n");
        if (id1 > id2) swap(id1, id2);
        int len = node[id2]-node[id1];
        printf("%d", min(len, node[0]-len));
    }

    return 0;
}