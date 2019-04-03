#include <iostream>
using namespace std;

//三种方法

//法一:通过定义式直接计算
long long C1(long long n, long long m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }

    for (int i = 1; i <= m; i++) {
        ans /= i;
    }

    for (int i = 1; i <= n-m; i++) {
        ans /= i;
    }
    return ans;
}

//法二:通过递推公式计算
long long C2(long long n, long long m) {
    if (m == 0 || m == n) return 1;
    return C2(n-1, m) + C2(n-1, m-1);
}

long long res[67][67] = {{0}};
long long C3(long long n, long long m) {
    if (m == 0 || m == 0) return 1;
    if (res[n][m] != 0) return res[n][m];
    return res[n][m] = C3(n-1, m)+C3(n-1, m-1);
}

const int n = 60;
void C4() {
    for (int i = 0; i < n; i++) {
        res[i][0] = res[i][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i/2; j++) {
            res[i][j] = res[i-1][j] + res[i-1][j-1];
            res[i][i-j] = res[i][j];
        }
    }

}

//法三:通过定义式的变形来计算
long long C(long long n, long long m) {
    long long ans = 1;
    for (long long i = 1; i <= m; i++) {
        ans = ans*(n-m+i)/i;
    }
    return ans;
}