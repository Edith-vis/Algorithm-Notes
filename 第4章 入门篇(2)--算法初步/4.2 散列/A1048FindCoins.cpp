#include <iostream>
using namespace std;

#define maxn 1001

int hashTable[maxn] = {0};

int main() {
    freopen("D:/in.txt", "r", stdin);

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        hashTable[a]++;
    }

    for (int i = 0; i < maxn && i < m; i++) {
        if (hashTable[i] > 0) {
            hashTable[i]--;
            if (hashTable[m-i] > 0) {
                if (i > m-i) {
                    printf("%d %d", m-i, i);
                } else {
                    printf("%d %d", i, m-i);
                }
                return 0;
            }
        }
    }

    printf("No Solution");

    return 0;
}