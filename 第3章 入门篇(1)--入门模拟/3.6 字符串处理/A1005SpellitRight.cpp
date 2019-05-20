#include <iostream>
#include <cstring>
using namespace std;

char str[101];

char num[10][8] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%s", str);
    int len = strlen(str);

    int ans = 0;
    for (int i = 0; i < len; i++) {
        ans += str[i]-'0';
    }

    //printf("%d", ans);
    string s = to_string(ans);
    for (int i = 0; i < s.length(); i++) {
        if (i != 0) printf(" ");
        printf("%s", num[s[i]-'0']);
    }
    return 0;
}