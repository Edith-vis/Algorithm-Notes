#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int pg, ps, pk, ag, as, ak;
    scanf("%d.%d.%d %d.%d.%d", &pg, &ps, &pk, &ag, &as, &ak);

    int ptotal = pg*17*29 + ps*29 + pk;
    int atotal = ag*17*29 + as*29 + ak;

    int total;
    if (ptotal > atotal) {
        printf("-");
        total = ptotal - atotal;
        
    } else {
        total = atotal - ptotal;
    }
    printf("%d.%d.%d", total/(17*29), (total/29)%17, total%29);
    return 0;
}