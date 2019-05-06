//数塔问题
#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 1010
int dp[maxn][maxn];//保存子问题的解 保存状态 dp[i][j]表示从第i行第j个数字出发的到达最底层的所有路径中能得到的最大和
int f[maxn][maxn];//保存数塔

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &f[i][j]);//读入数塔，从[1, 1]开始
        }
    }

    //边界
    for (int i = 1; i <= n; i++) {
        dp[n][i] = f[n][i];
    }
    //递推
    //从第n-1层不断往上计算出dp[i][j]
    for (int i = n-1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            //状态转移方程
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + f[i][j];
        }
    }
    printf("%d\n", dp[1][1]);
    return 0;
}