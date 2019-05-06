#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 101 //物品的最大件数
#define maxv 1000 //背包的最大容量

int dp[maxv];
int c[maxn], w[maxn];//体积 重量

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, V;
    scanf("%d%d", &n, &V);

    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    //边界
    for (int v = 0; v <= V; v++) {
        dp[v] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int v = V; v >= w[i]; v--) {//逆向访问
            dp[v] = max(dp[v], 
                        dp[v-w[i]] + c[i]);//状态转移方程
        }
    }

    //找dp[0...V]的最大值
    int ans = 0;
    for (int v = 0; v <= V; v++) {
        if (dp[v] > ans) {
            ans = dp[v];
        } 
    }

    printf("%d\n", ans);

    return 0;
}