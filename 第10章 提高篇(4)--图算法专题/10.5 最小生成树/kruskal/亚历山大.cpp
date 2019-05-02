#include <iostream>
#include <algorithm>
using namespace std;

#define MAXV 1010
#define INF 0x3fffffff

struct edge
{
    int u, v;
    int cost;
}E[MAXV];

bool cmp(edge a, edge b) {
    return a.cost < b.cost;
}

int n, m;
int father[MAXV];
int findFather(int x) {
    int a = x;//保存x的副本为a 为了路径压缩
    while (x != father[x])
    {
        x = father[x];
    }//现在的x是输入的x的"根节点" 即为应该返回的值

    //路径压缩 使沿途的结点的father都直接改为根(x)
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }

    return x;
}

int kruskal() {
    int ans = 0, Num_Edge = 0;
    sort(E, E+m, cmp);

    //别忘记并查集初始化
    for (int i = 0; i < n; i++) father[i] = i;

    for (int i = 0; i < m; i++) {
        int faU = findFather(E[i].u);
        int faV = findFather(E[i].v);
        if (faU != faV) {
            father[faU] = faV;//合并两个并查集 直接合并father
            ans += E[i].cost;
            Num_Edge++;
            if (Num_Edge == n-1) return ans;
        }
    }

    return -1;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].cost);
    }

    int ans = kruskal();
    printf("%d\n", ans);
    return 0;
}