#include <iostream>
using namespace std;

char ans[80][80];

int main() {
    freopen("D:/in.txt", "r", stdin);

    int len = 0;
    while (scanf("%s", ans[len++]) != EOF);

    for (int i = len-2; i >= 0; i--) {
        printf("%s", ans[i]);
        if (i != 0) printf(" ");
    }
    return 0;
}