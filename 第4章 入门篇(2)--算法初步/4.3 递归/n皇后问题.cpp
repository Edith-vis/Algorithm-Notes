#include <cstdio>
#include <algorithm>
#define maxn 11

int n, count = 0;
bool hash[maxn] = {false};
int P[maxn];

//暴力递归
void generateP1(int index) {
    if (index == n+1) {
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                if (abs(i-j) == abs(P[i]-P[j])){
                    flag = false;
                    break;
                }
            }
        }
        if (flag) count++;
        return;
    }

    for (int x = 1; x <= n; x++) {
        if (hash[x] == false) {
            P[index] = x;
            hash[x] = true;
            generateP1(index+1);
            hash[x] = false;
        }
    }
}

//回溯
void generateP2(int index) {
    if (index == n+1) {
        count++;
        return;
    }

    for (int x = 1; x <= n; x++) {
        if (hash[x] == false) {
            bool flag = true;
            for (int pre = 1; pre < index; pre++) {
                if (abs(pre-index) == abs(P[pre]-x)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                P[index] = x;
                hash[x] = true;
                generateP2(index+1);
                hash[x] = false;
            }
        }
    }
}

int main() {
    n = 8;
    generateP2(1);
    printf("%d\n", count);
    return 0;
}