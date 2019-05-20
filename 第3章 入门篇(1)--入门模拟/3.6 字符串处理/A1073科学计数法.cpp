#include <iostream>
#include <cstring>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    char str[10010];
    scanf("%s", str);
    if (str[0] == '-') printf("-");

    int posE = 0;//E的位置
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'E') {
            posE = i;
            break;
        }
    }
    //printf("%d", posE);

    //计算指数
    int exp = 0;
    for (int i = posE+2; i < strlen(str); i++) {
        exp = exp*10 + str[i] - '0';
    }
    //printf("%d", exp);
    if (exp == 0) {//特判指数部分为0
        for (int i = 1; i < posE; i++) {
            printf("%c", str[i]);
        }
    }


    if (str[posE+1] == '-') {//指数部分为负
        printf("0.");
        for (int i = 0; i < exp-1; i++) {
            printf("0");
        }
        printf("%c", str[1]);
        //小数点不打印
        for (int i = 3; i < posE; i++) {
            printf("%c", str[i]);
        }
    } else {//指数部分为正
        for (int i = 1; i < posE; i++) {
            if (str[i] == '.') continue;
            printf("%c", str[i]);
            if (i == exp+2 && posE-3 != exp) {//原小数点(位置为3)和E(位置为posE)之间的数字个数不能等于小数点右移位数exp
                printf(".");
            } 
        }

        for (int i = posE-3; i < exp; i++) {
            printf("0");
        }
    }

    return 0;
}