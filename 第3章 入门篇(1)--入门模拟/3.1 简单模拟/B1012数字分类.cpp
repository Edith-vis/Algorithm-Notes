#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    bool flag1 = false, flag2 = false, flag3 = false, flag4 = false, flag5 = false;
    int a1 = 0;//能被 5 整除的数字中所有偶数的和
    int a2 = 0;//将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算n1−n​2+n3−n​4⋯
    int flag = 1;
    int a3 = 0;//被 5 除后余 2 的数字的个数；
    double a4 = 0;//被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
    int cnt4 = 0;
    int a5 = -1;//被 5 除后余 4 的数字中最大数字
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (a%5 == 0) {
            
            if (a%2 == 0) {
                flag1 = true;
                a1+=a;
            }
        } else if (a%5 == 1) {
            flag2 = true;
            a2 += a*flag;
            flag = -flag;
        } else if (a%5 == 2) {
            flag3 = true;
            a3++;
        } else if (a%5 == 3) {
            flag4 = true;
            a4 += a;
            cnt4++;
        } else {
            flag5 = true;
            if (a > a5) a5 = a;
        }
    }

    if (flag1 == false) printf("N ");
    else printf("%d ", a1);

    if (flag2 == false) printf("N ");
    else printf("%d ", a2);

    if (flag3 == false) printf("N ");
    else printf("%d ", a3);

    if (flag4 == false) printf("N ");
    else printf("%.1f ", a4/cnt4);

    if (flag5 == false) printf("N");
    else printf("%d", a5);

    return 0;
}