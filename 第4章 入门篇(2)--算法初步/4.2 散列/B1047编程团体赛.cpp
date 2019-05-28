#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int id;
    int score;
}team[1001];

bool cmp(node a, node b) {
    return a.score > b.score;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < 1001; i++) {
        team[i].id = i;
        team[i].score = -1;
    }

    for (int i = 0; i < n; i++) {
        int tid, uid, score;
        scanf("%d-%d %d", &tid, &uid, &score);
        if (team[tid].score == -1) team[tid].score = 0;
        team[tid].score += score;
    }

    sort(team, team+1001, cmp);
    printf("%d %d", team[0].id, team[0].score);

    return 0;
}