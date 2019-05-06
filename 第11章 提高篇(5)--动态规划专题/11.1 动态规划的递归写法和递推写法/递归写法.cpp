//斐波那契数列
#include <iostream>
using namespace std;

#define maxn 1010
int dp[maxn] = {-1};

int F(int n) {
    if (n == 0 || n == 1) return 1;//递归边界
    if (dp[n] != -1) return dp[n];//已经计算过，直接返回结果，不再重复计算
    dp[n] = F(n-1) + F(n-2);//计算F(n)，并保存至dp[n]
    return dp[n];//返回F(n)的结果
}