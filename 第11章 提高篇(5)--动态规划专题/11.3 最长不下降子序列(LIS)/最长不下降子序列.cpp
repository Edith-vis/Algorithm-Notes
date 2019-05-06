#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 100
int A[maxn];
int dp[maxn];//dp[i]表示以编号为i的结点结尾的最长不下降子序列的长度

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[i] >= A[j] && dp[j]+1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }

        ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);
    return 0;
}