#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct bign {
    int len;
    int d[1000];
};

bign changeToBign(char str[]) {
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++) {
        a.d[a.len - i - 1] = str[i] - '0';
    }
    return a;
}

void show(bign a) {
    for (int i = a.len - 1; i >= 0; i--) {
        printf("%d", a.d[i]);
    }
}

bign _add(bign a, bign b) {
    bign ans;
    ans.len = 0;
    int r = 0;
    int i = a.len - 1, j = b.len - 1;
    while (i >= 0 && j >= 0) {
        ans.d[ans.len++] = (r + a.d[i] + b.d[i]) % 10;
        r = (r + a.d[i] + b.d[i]) / 10;
        i--; j--;
    }
    while (i >= 0) {
        ans.d[ans.len++] = (r + a.d[i]) % 10;
        r = (r + a.d[i]) / 10; 
        i--;       
    }
    while (j >= 0) {
        ans.d[ans.len++] = (r + b.d[i]) % 10;
        r = (r + b.d[i]) / 10;        
        j--;
    }
    if (r != 0) ans.d[ans.len++] = r;

    return ans;
}

bool isPalindromic(bign a) {
    int len = a.len;
    for (int i = 0; i < len/2; i++) {
        if (a.d[i] != a.d[len-i-1]) return false;
    }
    return true;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    char input[1000];
    int k;
    scanf("%s %d", input, &k);

    bign a = changeToBign(input);
    bign b;

    int i = 0;
    while (i < k && isPalindromic(a) == false) {
        b = a;
        reverse(b.d, b.d+b.len);
        a = _add(a, b);
        //show(a);
        i++;
    }

    show(a);
    printf("\n%d", i);

    return 0;
}