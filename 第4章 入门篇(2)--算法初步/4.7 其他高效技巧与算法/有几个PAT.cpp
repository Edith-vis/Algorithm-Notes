#include <iostream>
#include <cstring>
using namespace std;

#define MOD 1000000007
#define MAXN 100010

int leftNumP[MAXN] = {0};
char str[MAXN];

int main() {
    freopen("D:/in.txt", "r", stdin);
    gets(str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (i > 0) leftNumP[i] = leftNumP[i-1];
        if (str[i] == 'P') leftNumP[i]++;
    }

    int ans = 0, rightNumT = 0;
    for (int i = len-1; i >= 0; i--) {
        if(str[i] == 'T') rightNumT++;
        else if (str[i] == 'A') ans = (ans+rightNumT*leftNumP[i])%MOD;
    }
    printf("%d\n", ans);

    return 0;
}