#include <iostream>
using namespace std;

char m[12] = "10X98765432";
int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

int main() {
    freopen("D:/in.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    bool flag = false;
    for (int i = 0; i < n; i++) {
        char input[19];
        scanf("%s", input);

        //前17个字符是不是全为数字
        int cnt = 0;
        bool flag2 = false;
        for (int i = 0; i < 17; i++) {
            if (input[i] < '0' || input[i] > '9') {
                if (flag == false) {
                    flag = true;
                } else {
                    printf("\n");
                }
                printf("%s", input);
                flag2 = true;
            } else {
                cnt += weight[i]*(input[i]-'0');
            }
        }

        //校验位
        if (flag2 == false) {
            if (m[cnt%11] == input[17]) {}
            else {
                if (flag == false) {
                    flag = true;
                } else {
                    printf("\n");
                }
                printf("%s", input);          
            }
        }
    }

    if (flag == false) {
        printf("All passed");
    }

    return 0;
}