#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char s[7][4] = {
    "MON",
    "TUE",
    "WED",
    "THU",
    "FRI",
    "SAT",
    "SUN"
};

int main() {
    freopen("D:/in.txt", "r", stdin);

    //比较前两个字符串中相同的字符
    char c1[61], c2[61];
    scanf("%s", c1); scanf("%s", c2);
    char c3[61], c4[61];
    scanf("%s", c3); scanf("%s", c4);

    int len = min(strlen(c1), strlen(c2));
    int i;
    for (i = 0; i < len; i++) {
        if (c1[i] == c2[i] && c1[i] >= 'A' && c1[i] <= 'G') {
            printf("%s ", s[c1[i]-'A']);
            break;
        }
    }
    for (i++; i < len; i++) {
        if (c1[i] == c2[i]) {
            if (c1[i] >= '0' && c1[i] <='9') {
                printf("%02d:", c1[i]-'0');
                break;
            } else if (c1[i] >= 'A' && c1[i] <= 'N'){
                printf("%02d:", c1[i]-'A'+10);
                break;
            } 
        }
    }


    len = min(strlen(c3), strlen(c4));
    for (i = 0; i < len; i++) {
        if (c3[i] == c4[i]) {
            if((c3[i] >= 'a' && c3[i] <= 'z') || (c3[i] >= 'A' && c3[i] <= 'Z')){
                printf("%02d", i);
                break;
            }
        }
    }

    return 0;
}