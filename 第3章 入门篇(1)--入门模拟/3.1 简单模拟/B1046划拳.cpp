#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    int cnt1 = 0, cnt2 = 0;//!记得初始化
    int jhan, jhua, yhan, yhua;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &jhan, &jhua, &yhan, &yhua);
        if ((jhan+yhan == jhua || jhan+yhan == yhua) && 
            !(jhan+yhan == jhua && jhan+yhan == yhua)) {
            if (jhan+yhan == jhua) cnt2++;
            if (jhan+yhan == yhua) cnt1++;
            //printf("%d %d %d %d cnt1 = %d; cnt2 = %d\n", jhan, jhua, yhan, yhua, cnt1, cnt2);
        }
    }

    printf("%d %d", cnt1, cnt2);

    return 0;
}