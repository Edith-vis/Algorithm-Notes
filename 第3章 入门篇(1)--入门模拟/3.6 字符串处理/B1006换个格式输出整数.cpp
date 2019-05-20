#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n[4] = {0};
    int num;
    scanf("%d", &num);

    int len = 0;
    do {
        n[len++] = num % 10;
        num /= 10;
    } while (num != 0);


    for (int i = 1; i <= n[2]; i++) {
        printf("B");
    }
    for (int i = 1; i <= n[1]; i++) {
        printf("S");
    }
    for (int i = 1; i <= n[0]; i++) {
        printf("%d", i);
    }        
    return 0;
}