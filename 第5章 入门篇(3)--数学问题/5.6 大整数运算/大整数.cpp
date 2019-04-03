#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//存储
struct bign{
    int d[1000];
    int len;

    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

//字符串转bign结构体
bign change(char str[]) {
    bign result;
    result.len = strlen(str);
    for (int i = 0, j = result.len-1; i < result.len && j >= 0; i++, j--) {
        result.d[i] = str[j]-'0';
    }
    return result;
}

//比较两个bign的大小
int compare(bign a, bign b) {//a大:1 a小:-1 一样大:0
    if (a.len < b.len) return -1;
    else if (a.len > b.len) return 1;
    else {
        for (int i = 0; i < a.len; i++) {
            if (a.d[i] < b.d[i]) return -1;
            else if (a.d[i] > b.d[i]) return 1;
        }
        return 0;
    }
}

//高精度加法:两个对象都是非负整数
bign add (bign a, bign b) {
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len || i < b.len; i++) {
        c.d[c.len++] = (a.d[i]+b.d[i]+carry)%10;
        carry = (a.d[i]+b.d[i]+carry)/10;
    }
    if (carry != 0) c.d[c.len++] = carry;
    return c;
}

//高精度减法:a-b
bign sub(bign a, bign b) {
    bign c;
    for (int i = 0; i < a.len || i < b.len; i++) {
        if (a.d[i] < b.d[i]) {//不够减
            a.d[i+1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.len >= 2 && c.d[c.len-1] == 0) {
        c.len--;
    }
    return c;
}

//高精度与低精度的乘法
bign multi(bign a, int b) {
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len; i++) {
        c.d[c.len++] = (b*a.d[i]+carry)%10;
        carry = (b*a.d[i]+carry)/10;
    }
    while (carry != 0) {
        c.d[c.len++] = carry%10;
        carry /= 10;
    }
    return c;
}

//高精度与低精度的除法
bign divide(bign a, int b, int &r) {
    bign c;
    c.len = a.len;
    for (int i = a.len-1; i >= 0; i--) {
        r = r*10 + a.d[i];
        if (r < b) c.d[i] = 0;
        else {
            c.d[i] = r/b;
            r %= b;
        }
    }

    while (c.d[c.len-1] == 0 && c.len >= 2) c.len--;
    return c;
}

//打印bign
void print(bign a) {
    for (int i = a.len-1; i >= 0; i--) {
        printf("%d", a.d[i]);
    }
}

int main() {

    return 0;
}