#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    long long a, b;
    scanf("%lld %lld", &a, &b);
    long long ans = a+b;
    string s = to_string(ans);

    int len = s.length();
    for (int i = 0; i < len; i++) {
        printf("%c", s[i]);
        if (s[i] == '-') {
            continue;
        }
        if (i != len-1 && (len-i-1)%3 == 0) {
            printf(",");
        }
    }

    return 0;
}