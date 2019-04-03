#include <iostream>
using namespace std;

//四种方法

//法一:通过递推式计算

//a.递归
int res[100][100] = {{0}};
int p;
long long C(int n, int m) {
    if (m == 0 || m == n) return 1;
    if (res[n][m]) return res[n][m];
    return res[n][m] = (C(n-1, m) + C(n-1, m-1))%p;
}

//b.递推
int n;
void calC() {
    for (int i = 0; i <= n; i++) {
        res[i][0] = res[i][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i/2; j++) {
            res[i][j] = (res[i-1][j-1] + res[i-1][j])%p;
            res[i][i-j] = res[i][j];
        }
    }
}

//法二:根据定义式计算
#define maxn 101
int prime[maxn], pNum = 0;
bool d[maxn] = {false};//false为素数

void findPrime() {
    for (int i = 2; i < maxn; i++) {
        if (d[i] == true) continue;
        prime[pNum++] = i;
        for (int j = i+i; j < maxn; j += i) {
            d[j] = true;
        }
    }
}

//计算n的阶乘中含质因子p的个数
int cal(int n, int p) {
    int ans = 0;
    while (n) {
        ans += n/p;
        n /= p;
    }
    return ans;
}

//快速幂计算a^b
int binaryPow(int a, int b, int p) {
    if (b == 0) return 1;
    if (b%2) {
        return a*binaryPow(a, b-1, p)%p;
    } else {
        int t = binaryPow(a, b/2, p)%p;
        return t*t%p;
    }
}

//计算组合数对p取模
int C(int n, int m, int p) {
    int ans = 1;
    for (int i = 0; prime[i] <= n; i++) {
        int c = cal(n, prime[i]) - cal(m, prime[i]) - cal(n-m, prime[i]);
        ans = ans*binaryPow(prime[i], c, p)%p;
    }
    return ans;
}


//法三:通过定义式的变形来计算

//法四:Lucas定理
int Lucas(int n, int m) {
    if (m == 0) return 1;
    return C(n%p, m%p)*Lucas(n/p, m/p)%p;
}