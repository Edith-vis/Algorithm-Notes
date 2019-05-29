#include <iostream>
using namespace std;

#define maxn 100010

int n;

bool p[maxn] = {false};//p[i] == false 则数i为素数
int prime[maxn], pNum = 0;

void init() {
    for (int i = 2; i < maxn; i++) {
        if (p[i] == true) continue;
        prime[pNum++] = i;
        for (int j = 2; i*j < maxn; j++) {
            p[i*j] = true;
        }
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &n);
    init();

    int cnt = 0;
    for (int i = 1; i < pNum; i++) {
        if (prime[i] > n) break;
        if (prime[i] - prime[i-1] == 2) cnt++;
    }

    printf("%d\n", cnt);


    return 0;
}