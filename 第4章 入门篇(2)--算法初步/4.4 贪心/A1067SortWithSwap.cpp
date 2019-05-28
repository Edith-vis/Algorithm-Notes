#include <iostream>
using namespace std;

#define maxn 100010

int pos[maxn];//pos[i]存放数i所在位置

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    int num;
    int left = n-1;//left存放除0以外不在本位上的数的个数
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        pos[num] = i;//num所处的位置为i
        if (num == i && num != 0) left--;
    }

    int ans = 0;

    int k = 1;
    while (left > 0) {
        if (pos[0] == 0) {
            while (k < n) {
                if (pos[k] != k) {
                    swap(pos[0], pos[k]);
                    ans++;
                    break;
                }
                k++;
            }
        }

        while (pos[0] != 0) {
            swap(pos[0], pos[pos[0]]);
            ans++;
            left--;
        }
    }

    printf("%d\n", ans);

    return 0;
}