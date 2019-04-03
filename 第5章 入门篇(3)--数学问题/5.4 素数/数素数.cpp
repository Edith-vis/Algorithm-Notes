#include <iostream>
using namespace std;

#define maxn 10001
bool p[maxn] = {false};//false为素数
int prime[maxn], pNum = 1;

void FindPrime(int n) {
    for (int i = 2; i < maxn; i++) {
        if (p[i] == true) continue;
        prime[pNum++] = i;
        if (pNum > n) break;
        for (int j = i+i; j < maxn; j += i) {
            p[j] = true;
        }
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int m, n;
    scanf("%d %d", &m, &n);
    FindPrime(n);
    int cnt = 0;
    for (int i = m; i <= n; i++) {
        cnt++;
        if (cnt%10 != 1) printf(" ");
        printf("%d", prime[i]);
        if (cnt%10 == 0) printf("\n");
    }
    return 0;
}