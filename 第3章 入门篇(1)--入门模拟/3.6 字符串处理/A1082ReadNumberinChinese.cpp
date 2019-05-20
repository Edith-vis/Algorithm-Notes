#include <iostream>
#include <cstring>
using namespace std;

char num[10][5] = {
    "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};
char wei[5][5] = {
    "Shi", "Bai", "Qian", "Wan", "Yi"
};

int main() {
    freopen("D:/in.txt", "r", stdin);
    char str[15];
    gets(str);
    int len = strlen(str);
    int left = 0, right = len-1;
    if (str[0] == '-') {
        printf("Fu");
        left++;
    }

    while (left + 4 <= right) {
        right -= 4;
    }
    //left指向当前要输出的位，right指向与left同节的个位 4个为1节

    while (left < len) {
        bool flag = false;//flag == false表示没有重复的0
        bool isPrint = false;//isPrint == false表示该节没有输出过其中的位

        while (left <= right) {//从左至右处理某节中的每一位
            if (left > 0 && str[left] == '0') {//如果当前位为0
                flag = true;
            } else {//如果位不为0
                if (flag == true) {//如果存在累计的0
                    printf(" ling");
                    flag = false;
                }

                if (left > 0) printf(" ");
                printf("%s", num[str[left]-'0']);
                isPrint = true;
                if (left != right) printf(" %s", wei[right-left-1]);
            }
            left++;
        }

        if (isPrint && right != len-1) printf(" %s", wei[(len-right-1)/4 + 2]);

        right += 4;
    }
    return 0;
}