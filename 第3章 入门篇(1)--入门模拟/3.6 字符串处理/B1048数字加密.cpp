#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char c[14] = "0123456789JQK";

void reverse(char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len/2; i++) {
        char temp = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = temp;
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    char a[101], b[101];
    scanf("%s %s", a, b);

    reverse(a); reverse(b);

    char ans[101] = "";
    int len = max(strlen(a), strlen(b));
    for (int i = 0; i < len; i++) {
        int numa = i < strlen(a) ? a[i] - '0': 0;
        int numb = i < strlen(b) ? b[i] - '0': 0;

        if (i%2 == 1) {//偶数位
            ans[i] = numb-numa >= 0 ? numb-numa+'0' : numb-numa+10+'0';
        } else {//奇数位
            ans[i] = c[(numa+numb)%13];
        }
    }

    reverse(ans);
    puts(ans);

    return 0;
}