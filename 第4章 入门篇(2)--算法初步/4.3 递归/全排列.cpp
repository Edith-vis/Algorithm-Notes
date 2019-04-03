#include <cstdio>
#define maxn 11

bool hash[maxn] = {false};
int n, P[maxn];

void generateP(int index) {
    if (index == n+1) {
        for (int i = 1; i <= n; i++) {
            printf("%d", P[i]);
        }
        printf("\n");
        return;
    }

    for (int x = 1; x <= n; x++) {
        if (hash[x] == false) {
            P[index] = x;
            hash[x] = true;
            generateP(index+1);
            hash[x] = false;
        }
    }
}


int main() {
    n = 3;
    generateP(1);
    return 0;
}