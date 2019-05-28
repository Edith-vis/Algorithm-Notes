#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

#define maxn 10001

int timeToSecond(int h, int m, int s) {
    return h*3600+m*60+s;
}

struct record {
    int time;
    char id[10];
    int status;//1-in 0-out
}all[maxn], valid[maxn];

int num = 0;//有效记录的条数
map<string, int> parkTime;//车辆id->总停留时间

bool cmpByIdAndTime(record a, record b) {
    if (strcmp(a.id, b.id) != 0) return strcmp(a.id, b.id) < 0;//字典序
    else return a.time < b.time;
}

bool cmpByTime(record a, record b) {
    return a.time < b.time;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);

    int h, m, s;
    for (int i = 0; i < n; i++) {
        char status[5];
        scanf("%s %d:%d:%d %s", all[i].id, &h, &m, &s, status);
        int time = timeToSecond(h, m, s);
        all[i].time = time;
        if (strcmp(status, "in") == 0) all[i].status = 1;
        else all[i].status = 0;
    }

    sort(all, all+n, cmpByIdAndTime);

    //筛选有效记录、计算最长停留时间、计算map
    int maxTime = -1;
    for (int i = 0; i < n; i++) {
        if (i > 0 && strcmp(all[i-1].id, all[i].id) == 0 && all[i-1].status == 1 && all[i].status == 0) {
            valid[num++] = all[i-1];
            valid[num++] = all[i];

            int intime = all[i].time - all[i-1].time;
            if (parkTime.count(all[i].id) == 0) {
                parkTime[all[i].id] = 0;
            }
            parkTime[all[i].id] += intime;
            if (parkTime[all[i].id] > maxTime) {
                maxTime = parkTime[all[i].id];
            }
        }
    }

    sort(valid, valid+num, cmpByTime);
    int now = 0, numCar = 0;
    for (int i = 0; i < k; i++) {
        scanf("%d:%d:%d", &h, &m, &s);
        int time = timeToSecond(h, m, s);
        while (now < num && valid[now].time <= time) {
            if (valid[now].status == 1) numCar++;
            else numCar--;
            now++;
        }
        printf("%d\n", numCar);
    }

    for (auto it : parkTime) {
        if (it.second == maxTime) {
            printf("%s ", it.first.c_str());
        }
    }
    printf("%02d:%02d:%02d", maxTime/3600, maxTime/60%60, maxTime%60);

    return 0;
}