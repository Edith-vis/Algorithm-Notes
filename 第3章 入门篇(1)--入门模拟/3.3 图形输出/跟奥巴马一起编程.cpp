#include <cstdio>

int main() {
    freopen("D:/in.txt", "r", stdin);
    int num;
    char c;
    scanf("%d %c", &num, &c);

    int col = num;
    int row;
    if (col%2 == 0) {
        row = col/2;
    } else {
        row = (col+1)/2;
    }

    for (int i = 0; i < col; i++) {
        printf("%c", c);
    }
    printf("\n");
    for (int i = 1; i < row-1; i++) {
        printf("%c", c);
        for (int j = 1; j < col-1; j++) {
            printf(" ");
        }
        printf("%c\n", c);
    }
    for (int i = 0; i < col; i++) {
        printf("%c", c);
    }
    printf("\n");
    return 0;
}