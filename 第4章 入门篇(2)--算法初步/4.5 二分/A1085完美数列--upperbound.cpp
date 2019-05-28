#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 100010

int n, p;
long long input[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &input[i]);
    }
    sort(input, input + n);

    int ans = 1;
    for (int i = 0; i < n; i++) {
        long long temp = input[i]*p;
        int j = upper_bound(input+i+1, input+n, temp) - input;
        ans = max(j-i, ans);
    }

    printf("%d", ans);
    return 0;
}