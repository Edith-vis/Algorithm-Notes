#include <cstdio>
#include <cstring>

int main() {
    freopen("D:/in.txt", "r", stdin);
    char str[256];
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-1-i]) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}