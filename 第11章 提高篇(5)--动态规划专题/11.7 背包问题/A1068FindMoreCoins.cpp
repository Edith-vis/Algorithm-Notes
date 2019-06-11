#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 10100
#define maxw 110
int n, m;
int coins[maxn];
int dp[maxn][maxw] = {{0}};
bool selected[maxn][maxw] = {{false}};

bool cmp(int a, int b) {
    return a > b;
}


int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &coins[i]);
    }

    sort(coins + 1, coins + 1 + n, cmp);

    for (int i = 1; i <= n; i++) {
        for (int j = coins[i]; j <= m; j++) {
            if (dp[i-1][j-coins[i]] + coins[i] >= dp[i-1][j]) {
                dp[i][j] = dp[i-1][j-coins[i]] + coins[i];
                selected[i][j] = true;//放第i件物品
            } else {
                dp[i][j] = dp[i-1][j];
                selected[i][j] = false;
            }
        }
    }

    if (dp[n][m] != m) {
        printf("No Solution\n");
        return 0;
    }

    int j = m, i = n;
    while (1) {
        if (selected[i][j] == true) {
            printf("%d", coins[i]);
            j -= coins[i];
            if (j != 0) printf(" ");
        }
        i--;
        if (i == 0 || j == 0) break;
    }

    return 0;
}