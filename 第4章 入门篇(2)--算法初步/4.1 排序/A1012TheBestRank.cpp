#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct node {
    int id, best;
    int grade[4];
    int rank[4];
} person[2001];

int flag = -1;
bool cmp(node a, node b) {
    return a.grade[flag] > b.grade[flag];
} 

int exist[10000000] = {0};

char ans[5] = "ACME";

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &person[i].id, &person[i].grade[1], &person[i].grade[2], &person[i].grade[3]);
        person[i].grade[0] = round((person[i].grade[1] + person[i].grade[2] + person[i].grade[3])/3.0);//四舍五入
    }

    for (flag = 0; flag < 4; flag++) {
        sort(person, person+n, cmp);
        person[0].rank[flag] = 1;
        for (int i = 1; i < n; i++) {
            person[i].rank[flag] = person[i].grade[flag] == person[i-1].grade[flag] ? person[i-1].rank[flag] : i+1;
        }
    }

    for (int i = 0; i < n; i++) {
        person[i].best = 0;
        for (int j = 1; j < 4; j++) {
            if (person[i].rank[j] < person[i].rank[person[i].best]) {
                person[i].best = j;
            }
        }
        exist[person[i].id] = i+1;//排除0的干扰
    }

    for (int i = 0; i < m; i++) {
        int id;
        scanf("%d", &id);
        if (exist[id] != 0) {
            node temp = person[exist[id]-1];
            printf("%d %c\n", temp.rank[temp.best], ans[temp.best]);
        } else {
            printf("N/A\n");
        }
    }

    return 0;
}