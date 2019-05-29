#include <iostream>
#include <cstring>
using namespace std;

struct bign {
    int len;
    int d[10100];
    bign() {
        memset(d, 0, sizeof(d));
    }
};

bign change(char str[]) {
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < strlen(str); i++) {
        a.d[i] = str[i] - '0';
    }
    return a;
}

bign _divide(bign a, int b, int &r) {
    bign q;
    q.len = a.len;
    for (int i = 0; i < a.len; i++) {
        r = r*10 + a.d[i];
        if (r < b) q.d[i] = 0;
        else {
            q.d[i] = r/b;
            r = r%b;
        } 
    }
    return q;
}

void show(bign a) {
    bool flag = false;
    for (int i = 0; i < a.len; i++) {
        if (flag == false) {
            if (a.d[i] != 0) {
                flag = true;
                printf("%d", a.d[i]);
            } 
        } else {
            printf("%d", a.d[i]);
        }
    }
    if (flag == false) printf("0");
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    char str[10100];
    int b;
    scanf("%s %d", str, &b);
    bign a = change(str);
    int r = 0;
    bign q = _divide(a, b, r);
    show(q);
    printf(" %d", r);

    return 0;
}