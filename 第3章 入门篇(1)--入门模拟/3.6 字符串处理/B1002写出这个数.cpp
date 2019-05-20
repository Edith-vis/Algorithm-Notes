#include <iostream>
#include <cstring>
using namespace std;

char c[101];
int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%s", c);

    int num = 0;
    int len = strlen(c);
    for (int i = 0; i < len; i++) {
        num += c[i] - '0';
    }

    int n[40], len2 = 0;
    string shu[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    do {
        n[len2++] = num % 10;
        num /= 10;
    } while (num != 0);

    for (int i = len2-1; i >= 0; i--) {
        cout << shu[n[i]];
        if (i != 0) printf(" ");
    }
    return 0;
}