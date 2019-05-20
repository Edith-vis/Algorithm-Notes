#include <iostream>
#include <cstring>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int sum;
    char c;
    scanf("%d %c", &sum, &c);

    int n = 0;
    for ( ; 1 + 2*n*n + 4*n <= sum; n++){};
    n--;

    int column = 3 + 2 * (n-1);
    int row = n;
    
    int cnt = 0;
    //上半部分到1
    for (int i = 0; i <= row; i++) {
        int k = 0;
        for ( ; k < i; k++) {
            printf(" ");
        }
        for ( ; k < column-i; k++) {
            printf("%c", c);
            cnt++;
        }
        
        printf("\n");
    }

    //下半部分 从3开始
    for (int i = 1; i <= row; i++) {
        int k = 0;
        for ( ; k < column/2 - i; k++) {
            printf(" ");
        }
        for ( ; k <= column/2 + i; k++) {
            printf("%c", c);
            cnt++;
        }
        
        printf("\n");
    }

    printf("%d", sum-cnt);

    return 0;
}