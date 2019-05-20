#include <iostream>
using namespace std;

int num[40];

int main() {
    freopen("D:/in.txt", "r", stdin);

    int n, base;
    scanf("%d %d", &n, &base);

    int len = 0;
    do {
        num[len++] = n % base;
        n /= base;
    } while (n != 0);

    if (len == 1) {
        printf("Yes\n");
    } else {
        bool flag = true;
        for (int i = 0; i < len/2; i++) {
            if (num[i] != num[len-1-i]) {
                printf("No\n");
                flag = false;
                break;
            }
        }
        if (flag) printf("Yes\n");
    }


    for (int i = len-1; i >= 0; i--) {
        if (i != len-1) printf(" ");
        printf("%d", num[i]);
    }

    return 0;
}