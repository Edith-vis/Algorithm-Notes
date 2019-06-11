#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 10010
#define maxc 210
int n, m, L;
int fav[maxc], given[maxn];
int dp[maxc][maxn];


int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d\n%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &fav[i]);
    }
    scanf("%d", &L);
    for (int i = 1; i <= L; i++) {
        scanf("%d", &given[i]);
    }

    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= L; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= L; j++) {
            if (fav[i] == given[j]) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    printf("%d\n", dp[m][L]);


    return 0;
}