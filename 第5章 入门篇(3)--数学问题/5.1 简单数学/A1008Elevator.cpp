#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    int ans = 0;
    int now = 0, next;
    for (int i = 0; i < n; i++) {
        scanf("%d", &next);
        if (next > now) {
            ans += 6 * (next-now);
        } else if (next < now) {
            ans += 4 * (now-next);
        }
        ans += 5;
        now = next;
    }

    printf("%d\n", ans);

    return 0;
}