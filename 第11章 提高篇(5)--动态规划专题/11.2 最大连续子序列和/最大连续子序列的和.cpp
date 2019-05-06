#include <iostream>
#include <algorithm>
using namespace std;

//求所有连续子序列的和的最大值
#define maxn 1010
int A[maxn];//存放该序列
int dp[maxn];//dp[i]表示以i结尾的子序列的最大和

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n = 0;
    while (scanf("%d", &A[n++]) != EOF){}

    //边界
    dp[0] = A[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1]+A[i], A[i]);
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > ans) ans = dp[i];
    }

    printf("%d\n", ans);
    return 0;
}