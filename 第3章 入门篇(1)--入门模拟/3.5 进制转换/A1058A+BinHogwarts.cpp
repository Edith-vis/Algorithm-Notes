#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    long long pg, ps, pk, ag, as, ak;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &pg, &ps, &pk, &ag, &as, &ak);

    long long ptotal = pg*17*29 + ps*29 + pk;
    long long atotal = ag*17*29 + as*29 + ak;

    long long total = ptotal + atotal;
    printf("%lld.%lld.%lld", total/(17*29), (total/29)%17, total%29);
    return 0;
}