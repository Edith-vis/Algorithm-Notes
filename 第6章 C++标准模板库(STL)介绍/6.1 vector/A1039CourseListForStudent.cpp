#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getID(char str[]) {
    int id = 0;
    for (int i = 0; i < 3; i++) {
        id = id*26 + (str[i] - 'A');
    }
    id = id*10 + (str[3] - '0');
    return id;
}

vector<int> courses[200000];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);//n:查询人数 k:课程个数
    for (int i = 0; i < k; i++) {
        int id, num;
        scanf("%d%d", &id, &num);
        char name[5];
        for (int j = 0; j < num; j++) {
            scanf("%s", name);
            courses[getID(name)].push_back(id);
        }
    }

    for (int i = 0; i < n; i++) {
        char name[5];
        scanf("%s", name);
        int id = getID(name);
        printf("%s ", name);
        printf("%d", courses[id].size());
        if (courses[id].size() != 0) {
            sort(courses[id].begin(), courses[id].end());
            for (int i = 0; i < courses[id].size(); i++) {
                printf(" %d", courses[id][i]);
            }
        } 
        printf("\n");
    }

    return 0;
}