#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    double price;
    double dis;
} station[520];

bool cmp(node a, node b) {
    if (a.dis != b.dis) return a.dis < b.dis;
    else return a.price < b.price;
}

#define INF 0x3fffffff

int main() {
    freopen("D:/in.txt", "r", stdin);
    double cmax, d, d_avg; int n;
    scanf("%lf %lf %lf %d", &cmax, &d, &d_avg, &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &station[i].price, &station[i].dis);
    }

    //数组最后放置终点
    station[n].price = 0; 
    station[n].dis = d;

    sort(station, station+n, cmp);

    if (station[0].dis != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }

    int now_sta = 0;
    double cost_now = 0, now_tank = 0, MAX = cmax*d_avg;
    while (now_sta < n) {
        double min_price = INF;
        int next_sta = -1;
        for (int i = now_sta+1; i <= n && station[i].dis - station[now_sta].dis <= MAX; i++) {
            if (station[i].price < min_price) {
                min_price = station[i].price;
                next_sta = i;

                if (min_price < station[now_sta].price) {
                    break;
                }
            }
        }

        if (next_sta == -1) break;

        double need = (station[next_sta].dis - station[now_sta].dis) / d_avg;
        if (min_price < station[now_sta].price) {
            if (now_tank < need) {
                cost_now += (need - now_tank) * station[now_sta].price;
                now_tank = 0;
            } else {
                now_tank -= need;
            }
        } else {
            cost_now += (cmax - now_tank) * station[now_sta].price;
            now_tank = cmax - need;
        }

        now_sta = next_sta;
    }

    if (now_sta == n) {
        printf("%.02lf", cost_now);
    } else {
        printf("The maximum travel distance = %.02lf", station[now_sta].dis + MAX);
    }

    return 0;
}