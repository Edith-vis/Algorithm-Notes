#include <iostream>
#include <cstring>
using namespace std;

char num[1010];
int cnt[10] = {0};

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%s", num);

    int len = strlen(num);
    for (int i = 0; i < len; i++) {
        cnt[num[i]-'0']++;
    }

    bool flag = false;
    for (int i = 0; i < 10; i++) {
        if (cnt[i] != 0) {
            if (flag == false) {
                flag = true;
            } else {
                printf("\n");
            }
            printf("%d:%d", i, cnt[i]);
        }
    }

    return 0;
}