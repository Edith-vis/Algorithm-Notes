#include <iostream>
#include <cstring>
using namespace std;

char c[81];

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%s", c);
    int len = strlen(c);

    int n1 = (len+2)/3;
    int n3 = n1;
    int n2 = len+2-n1-n3;
    int row = n1, column = n2;

    int id = 0;
    for (int i = 0; i < row-1; i++) {
        for (int j = 0; j < column; j++) {
            if (j == 0) printf("%c", c[id]);
            else if (j == column - 1) printf("%c", c[len-1-id]);
            else printf(" ");
        }
        id++;
        printf("\n");
    }
    for (int j = 0; j < column; j++) {
        printf("%c", c[id++]);
    }

    return 0;
}