#include <iostream>
#include <cmath>
using namespace std;

const float CLK_TCK = 100.0;

long long c1, c2;

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%lld%lld", &c1, &c2);
    long long ans = round((c2-c1)/CLK_TCK);//round:四舍五入 !得用float才能除对!
    int h, m, s;
    h = ans / (60*60);
    m = (ans % (60*60)) / 60;
    s = (ans % (60*60)) % 60;
    printf("%02d:%02d:%02d", h, m, s);

    return 0;
}