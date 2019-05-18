#include <iostream>
using namespace std;

#define maxn 1010

struct stu{
    long long id;
    int kaoshi;
} Stu[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long id;
        int shiji, kaoshi;
        scanf("%lld %d %d", &id, &shiji, &kaoshi);
        Stu[shiji].id = id;
        Stu[shiji].kaoshi = kaoshi;
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int shiji;
        scanf("%d", &shiji);
        if (i != 0) printf("\n");
        printf("%16lld %d", Stu[shiji].id, Stu[shiji].kaoshi);
    }

    return 0;
}