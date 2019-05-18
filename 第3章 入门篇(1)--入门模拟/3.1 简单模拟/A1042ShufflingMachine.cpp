#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);

    int pos[55];
    int start[55];
    int end[55];

    int times = 0;//次数
    cin >> times;
    for (int i = 1; i < 55; i++) {
        scanf("%d", &pos[i]);
        end[i] = i;
    }

    //先把所有的牌从1-54编号 利用order做shuffle
    for (int i = 0; i < times; i++) {
        for (int j = 1; j < 55; j++) {
            start[j] = end[j];
        }
        for (int j = 1; j < 55; j++) {
            end[pos[j]] = start[j];
        }
    }

    //把牌从编号还原
    char c[6] = {"SHCDJ"};
    for (int i = 1; i < 55; i++) {
        if (i != 1) printf(" ");
        int num = end[i]-1;
        printf("%c%d", c[num/13], num%13+1);
    }

    return 0;
}