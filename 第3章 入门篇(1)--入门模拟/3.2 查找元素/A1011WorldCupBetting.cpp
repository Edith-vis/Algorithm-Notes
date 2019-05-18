#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);

    double ans = 1.0;
    char c[4] = "WTL";
    for (int i = 0; i < 3; i++) {
        double max_num = 0.0, num = 0.0;
        int max_id = -1;
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &num);
            if (num > max_num) {
                max_num = num;
                max_id = j;
            }
        }

        if (i != 0) printf(" ");
        printf("%c", c[max_id]);
        ans *= max_num;
    }
    printf(" %.2lf", (ans*0.65-1)*2);
    return 0;
}