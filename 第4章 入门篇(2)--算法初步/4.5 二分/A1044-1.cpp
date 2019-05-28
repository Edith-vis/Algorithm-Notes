#include <iostream>
using namespace std;

#define maxn 100010
int a[maxn];
int sum[maxn];

int minSum = 0x3fffffff;

int upper_bound(int left, int right, int x) {
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (sum[mid] > x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return right;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);

    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];
    }

    for (int i = 1; i <= n; i++) {
        int j = upper_bound(i, n + 1, m + sum[i-1]);
        if (sum[j - 1] - sum[i-1] == m) {
            minSum = m;
            break;
        } else if (j <= n && sum[j] - sum[i-1] < minSum) {
            minSum = sum[j] - sum[i-1];
        }
    }

    for (int i = 1; i <= n; i++) {
        int j = upper_bound(i, n + 1, minSum + sum[i-1]);
        //printf("%d\n", j);
        if (sum[j - 1] - sum[i-1] == minSum) {
            printf("%d-%d\n", i, j - 1);
        }
    }

    return 0;
}