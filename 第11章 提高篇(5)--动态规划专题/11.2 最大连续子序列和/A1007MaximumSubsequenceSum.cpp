#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 10010
int k;
int num[maxn];
int dp[maxn], s[maxn] = {0};


int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &k);
    bool flag = false;
    for (int i = 0; i < k; i++) {
        scanf("%d", &num[i]);
        if (num[i] >= 0)
            flag = true;
    }

    if (flag == false) {
        printf("0 %d %d\n", num[0], num[k-1]);
        return 0;
    }

    dp[0] = num[0];
    for (int i = 1; i < k; i++) {
        if (dp[i-1] + num[i] > num[i]) {
            dp[i] = dp[i - 1] + num[i];
            s[i] = s[i - 1];
        } else {
            dp[i] = num[i];
            s[i] = i;
        }
    }

    int ansID = 0;
    for (int i = 1; i < k; i++) {
        if (dp[i] > dp[ansID]) {
            ansID = i;
        }
    }
    printf("%d %d %d\n", dp[ansID], num[s[ansID]], num[ansID]);

        return 0;
}