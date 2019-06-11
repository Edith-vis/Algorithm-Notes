#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 10010
#define maxc 210
int n, m, L;
int hashTable[maxc];
int fav[maxc], given[maxn];
int dp[maxn];


int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d\n%d", &n, &m);
    memset(hashTable, -1, sizeof(hashTable));
    for (int i = 0; i < m; i++) {
        scanf("%d", &fav[i]);
        hashTable[fav[i]] = i;
    }
    scanf("%d", &L);
    int num = 0;
    int color;
    for (int i = 0; i < L; i++) {
        scanf("%d", &color);
        if (hashTable[color] >= 0) {
            given[num++] = hashTable[color];
        }
    }

    int ans = -1;
    for (int i = 0; i < num; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (given[j] <= given[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);

    return 0;
}