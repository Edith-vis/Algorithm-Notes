#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    string name;
    int id, score;
};

bool cmp1(node a, node b) {
    return a.id < b.id;
}

bool cmp2(node a, node b) {
    if (a.name != b.name) return a.name < b.name;
    else return a.id < b.id;
}

bool cmp3(node a, node b) {
    if (a.score != b.score) return a.score < b.score;
    else return a.id < b.id;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, c;
    scanf("%d %d", &n, &c);
    vector<node> stu(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &stu[i].id);
        cin >> stu[i].name;
        scanf("%d", &stu[i].score);
    }

    if (c == 1) {
        sort(stu.begin(), stu.end(), cmp1);
    } else if (c == 2) {
        sort(stu.begin(), stu.end(), cmp2);
    } else {
        sort(stu.begin(), stu.end(), cmp3);
    }

    for (int i = 0; i < n; i++) {
        if (i != 0) printf("\n");
        printf("%06d ", stu[i].id);
        cout << stu[i].name;
        printf(" %d", stu[i].score);
    }

    return 0;
}