#include <iostream>
#include <cstring>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n--) {
        char str[110];
        scanf("%s", str);
        int len = strlen(str);

        int num_p = 0, num_t = 0, num_other = 0;
        int pos_p = -1, pos_t = -1;
        for (int i = 0; i < len; i++) {
            if (str[i] == 'P') {
                num_p++;
                pos_p = i;
            } else if (str[i] == 'T') {
                num_t++;
                pos_t = i;
            } else if (str[i] != 'A') {
                num_other++;
            }
        }

        if (num_p != 1 || num_t != 1 || num_other != 0 || pos_t - pos_p < 2) {
            printf("NO\n");
            continue;
        }

        int x = pos_p, y = pos_t - pos_p - 1, z = len - pos_t - 1;
        if (x == z - x * (y - 1)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}