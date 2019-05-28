#include <cstdio>
#include <algorithm>
using namespace std;

struct mooncake{
    double store, sell, price;
} cake[1010];

bool cmp(mooncake a, mooncake b) {
    return a.price > b.price;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    double need;
    scanf("%d %lf", &n, &need);

    for (int i = 0; i < n; i++) {
        scanf("%lf", &cake[i].store);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &cake[i].sell);
        cake[i].price = cake[i].sell/cake[i].store;
    }
    sort(cake, cake+n, cmp);

    int i = 0;
    double total = 0.0;
    while (need > 0 && i < n) {
        if (need > cake[i].store) {
            need -= cake[i].store;
            total += cake[i].sell;
        } else {
            total += need*cake[i].price;
            need = 0;
        }
        i++;
    }
    printf("%.2lf\n", total);
    return 0;
}