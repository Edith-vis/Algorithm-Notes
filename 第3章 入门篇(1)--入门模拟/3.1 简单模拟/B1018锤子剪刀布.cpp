#include <iostream>
#include <algorithm>
using namespace std;

//C 代表“锤子”、J 代表“剪刀”、B 代表“布”
int win = 0, daw = 0, lose = 0;//甲胜、平、负的次数
int a1[3] = {0};//甲胜时B、C、J的次数
int b1[3] = {0};//乙胜时B、C、J的次数

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;
        if (a == b) {
            daw++;
        } else {
            if (a == 'B' && b == 'C') {//甲出布的时候赢
                win++;
                a1[0]++;
            } else if (a == 'C' && b == 'J') {//甲出锤的时候赢
                win++;
                a1[1]++;
            } else if (a == 'J' && b == 'B') {//甲出剪刀的时候赢
                win++;
                a1[2]++;
            } else if (a == 'B' && b == 'J') {//甲出布的时候输
                lose++;
                b1[2]++;
            } else if (a == 'C' && b == 'B') {//甲出锤的时候输
                lose++;
                b1[0]++;
            } else if (a == 'J' && b == 'C') {//甲出剪刀的时候输
                lose++;
                b1[1]++;
            }
        }
    }

    printf("%d %d %d\n", win, daw, lose);
    printf("%d %d %d\n", lose, daw, win);
    
    int maxJ = -1, maxY = -1;
    int J, Y;
    for (int i = 0; i < 3; i++) {
        if (a1[i] > maxJ) {
            maxJ = a1[i];
            J = i;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (b1[i] > maxY) {
            maxY = b1[i];
            Y = i;
        }
    }
    char zu[3] = {'B', 'C', 'J'};
    printf("%c %c", zu[J], zu[Y]);
    return 0;
}