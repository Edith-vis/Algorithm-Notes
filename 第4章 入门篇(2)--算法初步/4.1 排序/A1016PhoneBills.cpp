#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

int toll[24] = {0};

struct node {
    string name;
    int month, day, hour, minute;
    bool status; //status == false : off-line
};

bool cmp(node a, node b) {
    if (a.name != b.name) return a.name < b.name;
    else if (a.month != b.month) return a.month < b.month;
    else if (a.day != b.day) return a.day < b.day;
    else if (a.hour != b.hour) return a.hour < b.hour;
    else return a.minute < b.minute;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    for (int i = 0; i < 24; i++) {
        scanf("%d", &toll[i]);
    }
    int n;
    scanf("%d", &n);
    vector<node> data(n);

    char line[10];//临时存放on-line或off-line
    for (int i = 0; i < n; i++) {
        cin >> data[i].name;
        scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
        scanf("%s", line);
        if (strcmp(line, "on-line") == 0) data[i].status = true;
        else data[i].status = false;
    }

    sort(data.begin(), data.end(), cmp);

    //过滤无用信息
    map<string, vector<node> > customer;
    for (int i = 1; i < n; i++) {
        if (data[i-1].name == data[i].name && data[i-1].status == true && data[i].status == false) {
                customer[data[i].name].push_back(data[i-1]);
                customer[data[i].name].push_back(data[i]);
                //cout << data[i].status << " " << data[i-1].status << endl;
            }
    }

    for (auto it : customer) {
        cout << it.first;
        vector<node> temp = it.second;
        printf(" %02d\n", temp[0].month);
        int total = 0;
        for (int i = 1; i < temp.size(); i+=2) {
            node on = temp[i-1]; 
            node off = temp[i];
            printf("%02d:%02d:%02d ", on.day, on.hour, on.minute); 
            //cout << on.status << "!";
            printf("%02d:%02d:%02d ", off.day, off.hour, off.minute);
            //cout << off.status << "?";
            int time = 0, money = 0;
            while (on.day < off.day || on.hour < off.hour || on.minute < off.minute) {
                time++;
                money += toll[on.hour];
                on.minute++;
                if (on.minute >= 60) {
                    on.minute = 0;
                    on.hour++;
                }
                if (on.hour >= 24) {
                    on.hour = 0;
                    on.day++;
                }
            }
            printf("%d $%.2f\n", time, money/100.0);
            total += money;
        }
        printf("Total amount: $%.2f\n", total/100.0);
    }

    return 0;
}