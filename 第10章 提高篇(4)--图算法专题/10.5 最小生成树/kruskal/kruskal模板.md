```c++
struct edge{
    int u, v;//边的两个端点编号
    int cost;
}E[MAXV];

bool cmp(edge a, edge b) {
    return a.cost < b.cost;
}

int kruskal() {
    令最小生成树的边权之和为ans, 最小生成树的当前边数为Num_Edge;
    将所有边按照边权从小到大排序;
    for (从小到大枚举所有边) {
        if (当前测试边的两个端点在不同的连通块中) {
            将该边加入最小生成树中;
            ans += 测试边的边权;
            最小生成树的当前边数Num_Edge++;
            当前边数Num_Edge等于顶点数减一时结束循环;
        }
    }
    return ans;
}
```

```c++
int father[N];//并查集数组
int findFather(int x) {//并查集查询函数
}

int kruskal(int n, int m) {
    int ans = 0, Num_Edge = 0;
    for (int i = 1; i <= n; i++) {//假设题中结点编号为1-n
        father[i] = i;//并查集初始化
    }

    sort(E, E+m, cmp);

    for (int i = 0; i < m; i++) {//枚举所有的边
        int faU = findFather(E[i].u);
        int faV = findFather(E[i].v);//查询测试边两个端点所在集合的根节点
        if (faU != faV) {
            father[faU] = faV;
            ans += E[i].cost;
            Num_Edge++;
            if (Num_Edge >= n-1) return ans;
        }
    }

    return -1;//无法连通
}
```