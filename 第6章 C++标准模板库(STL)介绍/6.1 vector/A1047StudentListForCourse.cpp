#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

char names[400000][5]; int cnt = 0;
vector<int> courses[3000];

bool cmp(int a, int b) {//字典序
    return strcmp(names[a], names[b]) < 0;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        int cou_num;
        scanf("%s %d", names[cnt], &cou_num);
        for (int j = 0; j < cou_num; j++) {
            int course_id;
            scanf("%d", &course_id);
            courses[course_id].push_back(cnt);
        }
        cnt++;
    }

    for (int i = 1; i <= k; i++) {
        printf("%d %d\n", i, courses[i].size());
        sort(courses[i].begin(), courses[i].end(), cmp);
        for (int j = 0; j < courses[i].size(); j++) {
            printf("%s\n", names[courses[i][j]]);
        }
    }

    return 0;
}