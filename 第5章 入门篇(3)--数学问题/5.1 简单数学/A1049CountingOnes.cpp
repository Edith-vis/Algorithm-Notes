#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    int left, right, now;
    int a = 1;
    int ans = 0;
    while (n/a != 0) {
        left = n / (a*10);
        right = n % a;
        now = n / a - left * 10;
        //printf("left = %d now = %d right = %d\n", left, now, right);
        if (now == 0) ans += left*a;
        else if (now == 1) ans += left*a + right + 1;
        else ans += (left+1)*a;

        a *= 10;
    }

    printf("%d\n", ans);

    return 0;
}