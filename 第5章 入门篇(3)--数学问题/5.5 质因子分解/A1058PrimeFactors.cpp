#include <iostream>
#include <cmath>
using namespace std;

#define maxn 100001
bool p[maxn] = {false};//false是素数
int prime[maxn], num = 0;

void FindPrime() {
    for (int i = 2; i < maxn; i++) {
        if (p[i] == true) continue;
        prime[num++] = i;
        for (int j = i+i; j < maxn; j += i) {
            p[j] = true;
        }
    }
}

struct factor{
    int x, cnt;
}fac[10];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int m;
    scanf("%d", &m);
    FindPrime();

    if (m == 1) {
        printf("1=1");
    } else {
        int n = m;
        int fNum = 0;
        int sqr = (int)sqrt(1.0*n);
        for (int i = 0; i < num && prime[i] <= sqr; i++) {
            if (n%prime[i] == 0) {
                fac[fNum].x = prime[i];
                fac[fNum].cnt = 0;
                while (n%prime[i] == 0){
                    fac[fNum].cnt++;
                    n /= prime[i];
                }
                fNum++;
            }
            if (n == 1) break;
        }

        if (n != 1) {
            fac[fNum].x = n;
            fac[fNum++].cnt = 1;
        }
        printf("%d=", m);
        for (int i = 0; i < fNum; i++) {
            if (i > 0) printf("*");
            printf("%d", fac[i].x);
            if (fac[i].cnt > 1) printf("^%d", fac[i].cnt);
        }
    }

    return 0;
}