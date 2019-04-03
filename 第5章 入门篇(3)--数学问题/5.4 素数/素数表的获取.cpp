#include <iostream>
using namespace std;

#define maxn 101
bool p[maxn] = {false};//false为素数，true为合数
int prime[maxn], pNum = 0;

void FindPrime() {
    for (int i = 2; i < maxn; i++) {
        if (p[i] == true) continue;
        prime[pNum++] = i;
        for (int j = i+i; j < maxn; j += i) {
            p[j] = true;
        }
    }
}
