#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 100010

int n, p;
long long input[maxn];

//在[i+1, n-1]范围内查找第一个大于a[i]*p的数的位置j
int binarySearch(int i, long long x) {
    if (input[n-1] <= x) return n;
    int l = i+1, r = n-1, mid;
    while (l < r) {
        mid = (l+r)/2;
        if (input[mid] <= x) {
            l = mid + 1;
        }  else {
            r = mid;
        }
    }
    return l;
}

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
        int j = binarySearch(i, temp);
        ans = max(j-i, ans);
    }

    printf("%d", ans);
    return 0;
}