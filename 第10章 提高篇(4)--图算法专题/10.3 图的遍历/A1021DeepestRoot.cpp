#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define maxn 100010
int n;
vector<int> G[maxn];

int father[maxn];
bool isRoot[maxn];
bool vis[maxn];

int findFather(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }

    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);

    if (fa != fb) father[fa] = fb;
}

void init() {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        isRoot[i] = false;
    }
}

int calConnected() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (isRoot[findFather(i)] == false) {
            isRoot[findFather(i)] = true;
            ans++;
        }
    }
    return ans;
}

int maxHeight = 0;
vector<int> temp, ans;

void DFS(int height, int now) {
    if (height > maxHeight) {
        temp.clear();
        maxHeight = height;
        temp.push_back(now);
    } else if (height == maxHeight) {
        temp.push_back(now);
    }
    //printf("%d %d\n", height, now);
    vis[now] = true;
    for (int i = 0; i < G[now].size(); i++) {
        int v = G[now][i];
        if (vis[v] == true) continue;
        DFS(height+1, v);
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &n);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    init();
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
        Union(u, v);
        //printf("%d %d\n", u, v);
    }
    int block = calConnected();
    //printf("%d\n", block);
    if (block != 1) {
        printf("Error: %d components\n", block);
    } else {
        memset(vis, false, sizeof(vis));
        DFS(1, 1);
        ans = temp;
        memset(vis, false, sizeof(vis));
        DFS(1, ans[0]);
        for (int i = 0; i < temp.size(); i++) {
            ans.push_back(temp[i]);
        }
        sort(ans.begin(), ans.end());
        printf("%d\n", ans[0]);
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] != ans[i-1]) {
                printf("%d\n", ans[i]);
            }
        }
    }

    return 0;
}