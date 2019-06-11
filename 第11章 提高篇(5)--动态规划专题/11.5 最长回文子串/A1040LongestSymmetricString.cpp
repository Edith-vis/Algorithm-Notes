#include <iostream>
#include <cstring>
using namespace std;

#define maxn 1010
char input[maxn];
int dp[maxn][maxn];//dp[i][j] = 0表示i-j不回文

int main() {
    freopen("D:/in.txt", "r", stdin);
    cin.getline(input, maxn);

    int len = strlen(input), ans = 1;
    memset(dp, 0, sizeof(dp));
    //长度为1和长度为2的子串
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
        if (i < len -1) {
            if (input[i] == input[i+1]) {
                dp[i][i + 1] = 1;
                ans = 2;
            }
        }
    }

    for (int L = 3; L <= len; L++) {
        for (int i = 0; i + L - 1 < len; i++) {
            int j = i + L - 1;
            if (input[i] == input[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    
    printf("%d\n", ans);

        return 0;
}